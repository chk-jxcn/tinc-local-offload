LIB = libalias.a
OBJS = nat.o alias_ftp.o alias.o alias_db.o alias_proxy.o alias_util.o alias_mod.o arc4random.o

all: $(LIB)

$(LIB): $(OBJS)
	ar rcs libalias.a $(OBJS)

%.o : %.c
	cc -g -fPIC -I. -DNO_FW_PUNCH -D_BSD_SOURCE -D__BSD_SOURCE -D__FAVOR_BSD  -c $< -o $@

clean :
	rm *.o libalias.a
