#include "system.h"

#include "cipher.h"
#include "conf.h"
#include "connection.h"
#include "control.h"
#include "device.h"
#include "digest.h"
#include "ecdsa.h"
#include "graph.h"
#include "logger.h"
#include "names.h"
#include "net.h"
#include "netutl.h"
#include "process.h"
#include "protocol.h"
#include "route.h"
#include "rsa.h"
#include "script.h"
#include "subnet.h"
#include "utils.h"
#include "xalloc.h"


#include "lctrie/lctrie_ip.h"
#include "lctrie/lctrie.h"

static lct_t* t;
static lct_subnet_t *p;
static splay_tree_t *node_in_route;
static char *default_nodename;
note_t *default_node;

#define BGP_MAX_ENTRIES 400000

static int node_compare(const lct_tinc_route_t *a, const lct_tinc_route_t *b)
{
		return strcmp(a->dest, b->dest);
}

static free_route_node(lct_tinc_route_t *r) 
{
	if (r->dest)
		free(r->dest);
	free(r);
}


static init_route_nodes(void) 
{
	node_in_route = splay_alloc_tree((splay_compare_t) node_compare, (splay_action_t) free_route_node);
}

static lct_tinc_route_t *lookup_route_node(char *dest) 
{
	lct_tinc_route_t n = {0};
	n.dest = dest;
	return splay_search(node_in_route, &n);
}

static void insert_route_node(lct_tinc_route_t *r) 
{
	splay_insert(node_in_route, r);
}

static int load_from_file(char *file, lct_subnet_info_t *info, uint32_t *current_num, uint32_t *max_num)
{
	uint32_t num = *current_num;
	const char *pattern = "^((\\d{1,3}\\.){3}\\d{1,3})\\/(\\d{1,2})";
	FILE *infile;
	char *line = NULL;
	size_t line_len = 0;
	pcre *re;
	char input[INET_ADDRSTRLEN];
	char *substr_start;
	int substr_len;

	const char *error;
	int erroffset;
#define BGP_PREFIX_OVECCOUNT 3 * 5 // we'll have 5 substring matches
	int ovector[BGP_PREFIX_OVECCOUNT];

	lct_subnet_t *prefix = p;


	if (!(infile = fopen(filename, "r"))) {
		fprintf(stderr, "%s: %s\n", filename, strerror(errno));
		return -1;
	}

	re = pcre_compile(pattern, 0, &error, &erroffset, NULL);
	if (!re) {
		fprintf(stderr, "PCRE compilation failed at offset: %d: %s\n",
				erroffset, error);
		return -1;
	}

	while (-1 != getline(&line, &line_len, infile)) {
		if ( line[0] == '#' )
			continue;
		line[strcspn(line, "\n")] = 0;
		rc = pcre_exec(re,
				0,
				line,
				strlen(line),
				0,
				0,
				ovector,
				BGP_PREFIX_OVECCOUNT);
		if (rc < 0) {
			switch (rc) {
				case PCRE_ERROR_NOMATCH:
					fprintf(stderr, "invalid line: %s\n", line);
					break;

				default:
					fprintf(stderr, "Matching error %d on line: %s\n", rc, line);
					break;
			}
			continue;
		}
		substr_start = line + ovector[2*1];
		substr_len = ovector[2*1 + 1] - ovector[2*1];
		snprintf(input, sizeof(input), "%.*s", substr_len, substr_start);
		if (!inet_pton(AF_INET, input, &(prefix[num].addr))) {
			fprintf(stderr, "ERROR: %s is not a valid IP address: %s\n", input, strerror(errno));
			continue;
		}
		prefix[num].addr = ntohl(prefix[num].addr);
		substr_start = line + ovector[2*3];
		substr_len = ovector[2*3 + 1] - ovector[2*3];
		snprintf(input, sizeof(input), "%.*s", substr_len, substr_start);
		if (ULONG_MAX == (prefix[num].len = strtoul(input, NULL, 10))) {
			fprintf(stderr, "ERROR: %s is not a valid integer: %s\n", input, strerror(errno));
			continue;
		}
		if ((prefix[num].len == 0) || (prefix[num].len > 32)) {
			fprintf(stderr, "ERROR: %d is not a valid prefix length\n", prefix[num].len);
			continue;
		}
		prefix[num].info = *info;
		num++;
		if (num >= *max_num) {
			prefix = p = realloc(p, sizeof(lct_subnet_t) * (*max_num) *2);
			*max_num = (*max_num) * 2;
		}
	}
	uint32_t num_this = num - *current_num;
	if (info->type == IP_SUBNET_TINC_ROUTE) {
		(lct_tinc_route_t*)(info->user)->num = num_this;
	}
	*current_num = num;

	free(line);
	pcre_free(re);
	fclose(infile);
	return num_this;
}

static void build_lct(uint32_t num) {
	subnet_mask(p, num);
	qsort(p, num, sizeof(lct_subnet_t), subnet_cmp);
	num -= subnet_dedup(p, num);
	p = realloc(p, num * sizeof(lct_subnet_t));
	lct_ip_stats_t *stats = (lct_ip_stats_t *) calloc(num, sizeof(lct_ip_stats_t));
	subnet_prefix(p, stats, num);
	memset(t, 0, sizeof(lct_t));
	lct_build(t, p, num);
}

int reload_route_table()
{
	bool load_local_route;
	DIR *dir;
	struct dirent *ent;
	char dname[PATH_MAX];
	char fname[1024];
	char *local_offload_file;
	uint32_t subnet_num = 0;
	uint32_t max_subnet = BGP_MAX_ENTRIES;
	setlocale(LC_NUMERIC, "");

	if (t != NULL) {
		lct_free(t);
		t = NULL;
	}

	if (p != NULL) {
		free(p);
	}
	p = (lct_subnet_t *)calloc(sizeof(lct_subnet_t), max_subnet);

	if (node_in_route != NULL) {
		splay_delete_tree(node_tree);
	}

	if (default_nodename != NULL) {
		free(default_nodename);
	}
	default_node = NULL;

	init_route_nodes();

	if (get_config_string(lookup_config(config_tree, "DefaultNode"), &default_nodename))
		default_node = lookup_node(default_nodename);

	// config of local subnet
	if(lookup_config(config_tree, "DeviceLocal") && 
			get_config_string(lookup_config(config_tree, "OffloadSubnets"), &local_offload_file)) {
		lct_subnet_info_t info;
		info.type = IP_SUBNET_TINC_LOCAL;	
		snprintf(fname, sizeof(fname), "%s" SLASH "%s", confbase, local_offload_file);
		load_from_file(fname, &info, &subnet_num, &max_subnet);
	}
	// config of route table
	snprintf(dname, sizeof(dname), "%s" SLASH "route", confbase);
	dir = opendir(dname);

	if(!dir) {
		logger(DEBUG_ALWAYS, LOG_ERR, "Could not open %s: %s", dname, strerror(errno));
		if (subnet_num == 0) {
			return 0;
		}
	}

	while((ent = readdir(dir))) {
		if(!check_id(ent->d_name)) {
			continue;
		}

		node_t *n = lookup_node(ent->d_name);
		lct_tinc_route_t *r = (lct_tinc_route_t*)calloc(sizeof(lct_tinc_route_t), 1);
		lct_subnet_info_t info;
		info.type = IP_SUBNET_TINC_ROUTE;
		info.usr.data = r;

		r->dest = strdup(ent->d_name);
		r->node = n;

		insert_route_node(r);
		snprintf(fname, sizeof(fname), "%s" SLASH "%s", dname, ent->d_name);
		load_from_file(fname, &info, &subnet_num, &max_subnet);
	}
	if (*subnet_num > 0) {
		t = calloc(sizeof(lct_t), 1);
		build_lct(*subnet_num);
	}

}

node_t* lct_route(ipv4_t address, uint32_t *type)
{
	lct_subnet_t *subnet = NULL;
	uint32_t dest = ntohl(address);
	
	if (!t) {
		return NULL;
	}

	subnet = lct_find(t, dest);
	if (!subnet) {
		return NULL;
	}
	*type = subnet->info.type;
	if(*type == IP_SUBNET_TINC_LOCAL) {
		lct_tinc_route_t *r = (lct_tinc_route_t *)subnet->info.user;
		if (r->node == NULL) {
			node_t *n = lookup_node(r->dest);
			r->node = n;
		}
		return n;
	}
	return NULL;
}

void lct_add_node(node_t *node)
{
	lct_tinc_route_t *n = lookup_route_node(node->name);
	if (n) {
		n->node = node;
	}
	if (default_nodename && !strcmp(default_nodename, node->name)) {
		default_node = node;
	}
}

void lct_del_node(node_t *node)
{
	lct_tinc_route_t *n = lookup_route_node(node->name);
	if (n) {
		n->node = NULL;
	}
	if (default_nodename && !strcmp(default_nodename, node->name)) {
		default_node = NULL;
	}
}

void init_localoffload(char *filename)
{
	int num = 0;
	int rc;
	setlocale(LC_NUMERIC, "");
	if (!(p = (lct_subnet_t *)calloc(sizeof(lct_subnet_t), BGP_MAX_ENTRIES))) {
		return;
	}
	if (0 > (rc = read_prefix_table(filename, &p[0], BGP_MAX_ENTRIES))) {
		return;
	}
	num += rc;

	subnet_mask(p, num);
	qsort(p, num, sizeof(lct_subnet_t), subnet_cmp);
	num -= subnet_dedup(p, num);
	p = realloc(p, num * sizeof(lct_subnet_t));
	lct_ip_stats_t *stats = (lct_ip_stats_t *) calloc(num, sizeof(lct_ip_stats_t));
	subnet_prefix(p, stats, num);

	memset(&t, 0, sizeof(lct_t));
	lct_build(&t, p, num);
	success = 1;
}

int match_localoffload(uint32_t dest)
{
	lct_subnet_t *p, *subnet = NULL;
	subnet = lct_find(&t, dest);
	if (subnet)
		return 1;
	return 0;
}

void clean_localoffload()
{
	if (success == 0)
		return;
	lct_free(&t);
	free(p);
	success = 0;
}
