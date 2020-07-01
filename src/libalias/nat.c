#include <sys/types.h>
#include <netinet/in.h>
#include <alias.h>

static struct libalias *la = 0;
static int success = 0;

extern struct proto_handler *handlers_ftp;

void nat_init(struct in_addr addr)
{
    la = LibAliasInit(0);
    if (la == 0)
        return;

    LibAliasSetAddress(la, addr);
    //LibAliasAttachHandlers(handlers_ftp);
    success = 1;
}

void nat_in(char *buffer, int maxpacketsize)
{
    if (success != 1)
        return;
    LibAliasIn(la, buffer, maxpacketsize);

}

void nat_out(char *buffer, int maxpacketsize)
{
    if (success != 1)
        return;
    LibAliasOut(la, buffer, maxpacketsize);
}
