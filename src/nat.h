// support nat in tinc

void nat_init(struct in_addr addr);
void nat_in(char *buffer, int maxpacketsize);
void nat_out(char *buffer, int maxpacketsize);

