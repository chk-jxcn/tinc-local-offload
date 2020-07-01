/* read route tables and map it to node */

// define for tinc
#define IP_SUBNET_TINC_LOCAL  10
#define IP_SUBNET_TINC_ROUTE  11

typedef struct lct_tinc_route {
	char *dest;
	node_t *node;	
	uint32_t num;
} lct_tinc_route_t;

extern int reload_route_table();
extern node_t* lct_route(ipv4_t address, uint32_t *type);
extern void lct_add_node(node_t *node);
extern void lct_del_node(node_t *node);

