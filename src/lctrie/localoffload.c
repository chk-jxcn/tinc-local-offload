#include <stdlib.h>
#include <stdio.h>
#include <libgen.h>
#include <string.h>
#include <errno.h>
#include <time.h>
#include <locale.h>

#include <sys/time.h>

#include "lctrie_ip.h"
#include "lctrie_bgp.h"
#include "lctrie.h"

static lct_t t;
static lct_subnet_t *p;
static int success = 0;

#define BGP_MAX_ENTRIES 400000

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
