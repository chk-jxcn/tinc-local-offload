#ifndef TINC_LOCALOFFLOAD_H
#define TINC_LOCALOFFLOAD_H

extern void init_localoffload(char *filename);
extern int match_localoffload(uint32_t ip);
extern void clean_localoffload();

#endif
