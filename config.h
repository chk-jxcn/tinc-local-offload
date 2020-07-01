/* config.h.  Generated from config.h.in by configure.  */
/* config.h.in.  Generated from configure.ac by autoheader.  */

/* Disable support for the legacy (tinc 1.0) protocol */
/* #undef DISABLE_LEGACY */

/* Support for jumbograms (packets up to 9000 bytes) */
/* #undef ENABLE_JUMBOGRAMS */

/* Support for tunemu */
/* #undef ENABLE_TUNEMU */

/* Support for UML */
/* #undef ENABLE_UML */

/* Support for VDE */
/* #undef ENABLE_VDE */

/* Define to 1 if you have the <arpa/inet.h> header file. */
#define HAVE_ARPA_INET_H 1

/* Define to 1 if you have the `asprintf' function. */
#define HAVE_ASPRINTF 1

/* Define to 1 if you have the `BN_GENCB_new' function. */
#define HAVE_BN_GENCB_NEW 1

/* Unknown BSD variant */
/* #undef HAVE_BSD */

/* have curses support */
/* #undef HAVE_CURSES */

/* Define to 1 if you have the <curses.h> header file. */
/* #undef HAVE_CURSES_H */

/* Cygwin */
/* #undef HAVE_CYGWIN */

/* Define to 1 if you have the `daemon' function. */
#define HAVE_DAEMON 1

/* Darwin (MacOS/X) */
/* #undef HAVE_DARWIN */

/* Define to 1 if you have the declaration of `EVP_aes_256_cfb', and to 0 if
   you don't. */
#define HAVE_DECL_EVP_AES_256_CFB 1

/* Define to 1 if you have the declaration of `OpenSSL_add_all_algorithms',
   and to 0 if you don't. */
#define HAVE_DECL_OPENSSL_ADD_ALL_ALGORITHMS 1

/* Define to 1 if you have the declaration of `res_init', and to 0 if you
   don't. */
#define HAVE_DECL_RES_INIT 1

/* Define to 1 if you have the `devname' function. */
#define HAVE_DEVNAME 1

/* Define to 1 if you have the <dirent.h> header file. */
#define HAVE_DIRENT_H 1

/* DragonFly */
/* #undef HAVE_DRAGONFLY */

/* Define to 1 if you have the `ERR_remove_state' function. */
#define HAVE_ERR_REMOVE_STATE 1

/* Define to 1 if you have the `EVP_CIPHER_CTX_new' function. */
#define HAVE_EVP_CIPHER_CTX_NEW 1

/* Define to 1 if you have the `EVP_EncryptInit_ex' function. */
#define HAVE_EVP_ENCRYPTINIT_EX 1

/* Define to 1 if you have the `fchmod' function. */
#define HAVE_FCHMOD 1

/* Define to 1 if you have the `fdevname' function. */
#define HAVE_FDEVNAME 1

/* Define to 1 if you have the `flock' function. */
#define HAVE_FLOCK 1

/* Define to 1 if you have the `fork' function. */
#define HAVE_FORK 1

/* FreeBSD */
#define HAVE_FREEBSD 1

/* Define to 1 if you have the <gcrypt.h> header file. */
/* #undef HAVE_GCRYPT_H */

/* Define to 1 if you have the <getopt.h> header file. */
#define HAVE_GETOPT_H 1

/* getopt_long() */
#define HAVE_GETOPT_LONG 1

/* Define to 1 if you have the `gettimeofday' function. */
#define HAVE_GETTIMEOFDAY 1

/* Define to 1 if you have the `HMAC_CTX_new' function. */
#define HAVE_HMAC_CTX_NEW 1

/* Define to 1 if you have the <inttypes.h> header file. */
#define HAVE_INTTYPES_H 1

/* Define to 1 if you have the `resolv' library (-lresolv). */
/* #undef HAVE_LIBRESOLV */

/* Define to 1 if you have the `socket' library (-lsocket). */
/* #undef HAVE_LIBSOCKET */

/* Define to 1 if you have the <libvdeplug_dyn.h> header file. */
/* #undef HAVE_LIBVDEPLUG_DYN_H */

/* Linux */
/* #undef HAVE_LINUX */

/* Define to 1 if you have the <linux/if_tun.h> header file. */
/* #undef HAVE_LINUX_IF_TUN_H */

/* enable lzo compression support */
#define HAVE_LZO 1

/* Define to 1 if you have the <lzo1x.h> header file. */
/* #undef HAVE_LZO1X_H */

/* Define to 1 if you have the <lzo2/lzo1x.h> header file. */
/* #undef HAVE_LZO2_LZO1X_H */

/* Define to 1 if you have the <lzo/lzo1x.h> header file. */
#define HAVE_LZO_LZO1X_H 1

/* Define to 1 if you have the <memory.h> header file. */
#define HAVE_MEMORY_H 1

/* MinGW */
/* #undef HAVE_MINGW */

/* have miniupnpc support */
/* #undef HAVE_MINIUPNPC */

/* Define to 1 if you have the <miniupnpc/miniupnpc.h> header file. */
/* #undef HAVE_MINIUPNPC_MINIUPNPC_H */

/* Define to 1 if you have the `mlockall' function. */
#define HAVE_MLOCKALL 1

/* Define to 1 if you have the `nanosleep' function. */
#define HAVE_NANOSLEEP 1

/* NetBSD */
/* #undef HAVE_NETBSD */

/* Define to 1 if you have the <netdb.h> header file. */
#define HAVE_NETDB_H 1

/* Define to 1 if you have the <netinet/icmp6.h> header file. */
#define HAVE_NETINET_ICMP6_H 1

/* Define to 1 if you have the <netinet/if_ether.h> header file. */
#define HAVE_NETINET_IF_ETHER_H 1

/* Define to 1 if you have the <netinet/in6.h> header file. */
/* #undef HAVE_NETINET_IN6_H */

/* Define to 1 if you have the <netinet/in.h> header file. */
#define HAVE_NETINET_IN_H 1

/* Define to 1 if you have the <netinet/in_systm.h> header file. */
#define HAVE_NETINET_IN_SYSTM_H 1

/* Define to 1 if you have the <netinet/ip6.h> header file. */
#define HAVE_NETINET_IP6_H 1

/* Define to 1 if you have the <netinet/ip.h> header file. */
#define HAVE_NETINET_IP_H 1

/* Define to 1 if you have the <netinet/ip_icmp.h> header file. */
#define HAVE_NETINET_IP_ICMP_H 1

/* Define to 1 if you have the <netinet/tcp.h> header file. */
#define HAVE_NETINET_TCP_H 1

/* Define to 1 if you have the <netpacket/packet.h> header file. */
/* #undef HAVE_NETPACKET_PACKET_H */

/* Define to 1 if you have the <net/ethernet.h> header file. */
#define HAVE_NET_ETHERNET_H 1

/* Define to 1 if you have the <net/if_arp.h> header file. */
#define HAVE_NET_IF_ARP_H 1

/* Define to 1 if you have the <net/if.h> header file. */
#define HAVE_NET_IF_H 1

/* Define to 1 if you have the <net/if_tap.h> header file. */
#define HAVE_NET_IF_TAP_H 1

/* Define to 1 if you have the <net/if_tun.h> header file. */
#define HAVE_NET_IF_TUN_H 1

/* Define to 1 if you have the <net/if_types.h> header file. */
#define HAVE_NET_IF_TYPES_H 1

/* Define to 1 if you have the <net/if_utun.h> header file. */
/* #undef HAVE_NET_IF_UTUN_H */

/* Define to 1 if you have the <net/tap/if_tap.h> header file. */
/* #undef HAVE_NET_TAP_IF_TAP_H */

/* Define to 1 if you have the <net/tun/if_tun.h> header file. */
/* #undef HAVE_NET_TUN_IF_TUN_H */

/* OpenBSD */
/* #undef HAVE_OPENBSD */

/* Define to 1 if you have the <openssl/engine.h> header file. */
#define HAVE_OPENSSL_ENGINE_H 1

/* Define to 1 if you have the <openssl/err.h> header file. */
#define HAVE_OPENSSL_ERR_H 1

/* Define to 1 if you have the <openssl/evp.h> header file. */
#define HAVE_OPENSSL_EVP_H 1

/* Define to 1 if you have the <openssl/pem.h> header file. */
#define HAVE_OPENSSL_PEM_H 1

/* Define to 1 if you have the <openssl/rand.h> header file. */
#define HAVE_OPENSSL_RAND_H 1

/* Define to 1 if you have the <openssl/rsa.h> header file. */
#define HAVE_OPENSSL_RSA_H 1

/* Define to 1 if you have the <openssl/sha.h> header file. */
#define HAVE_OPENSSL_SHA_H 1

/* Define to 1 if you have the `putenv' function. */
#define HAVE_PUTENV 1

/* Define to 1 if you have the `RAND_bytes' function. */
#define HAVE_RAND_BYTES 1

/* have readline support */
/* #undef HAVE_READLINE */

/* Define to 1 if you have the <readline/history.h> header file. */
/* #undef HAVE_READLINE_HISTORY_H */

/* Define to 1 if you have the <readline/readline.h> header file. */
/* #undef HAVE_READLINE_READLINE_H */

/* Define to 1 if you have the `recvmmsg' function. */
#define HAVE_RECVMMSG 1

/* Define to 1 if you have the <resolv.h> header file. */
#define HAVE_RESOLV_H 1

/* Define to 1 if you have the `RSA_set0_key' function. */
#define HAVE_RSA_SET0_KEY 1

/* Solaris/SunOS */
/* #undef HAVE_SOLARIS */

/* Define to 1 if you have the <stdint.h> header file. */
#define HAVE_STDINT_H 1

/* Define to 1 if you have the <stdlib.h> header file. */
#define HAVE_STDLIB_H 1

/* Define to 1 if you have the <strings.h> header file. */
#define HAVE_STRINGS_H 1

/* Define to 1 if you have the <string.h> header file. */
#define HAVE_STRING_H 1

/* Define to 1 if you have the `strsignal' function. */
#define HAVE_STRSIGNAL 1

/* Define to 1 if the system has the type `struct arphdr'. */
#define HAVE_STRUCT_ARPHDR 1

/* Define to 1 if the system has the type `struct ether_arp'. */
#define HAVE_STRUCT_ETHER_ARP 1

/* Define to 1 if the system has the type `struct ether_header'. */
#define HAVE_STRUCT_ETHER_HEADER 1

/* Define to 1 if the system has the type `struct icmp'. */
#define HAVE_STRUCT_ICMP 1

/* Define to 1 if the system has the type `struct icmp6_hdr'. */
#define HAVE_STRUCT_ICMP6_HDR 1

/* Define to 1 if the system has the type `struct ip'. */
#define HAVE_STRUCT_IP 1

/* Define to 1 if the system has the type `struct ip6_hdr'. */
#define HAVE_STRUCT_IP6_HDR 1

/* Define to 1 if the system has the type `struct nd_neighbor_solicit'. */
#define HAVE_STRUCT_ND_NEIGHBOR_SOLICIT 1

/* Define to 1 if the system has the type `struct nd_opt_hdr'. */
#define HAVE_STRUCT_ND_OPT_HDR 1

/* Define to 1 if you have the <syslog.h> header file. */
#define HAVE_SYSLOG_H 1

/* Define to 1 if you have the <sys/file.h> header file. */
#define HAVE_SYS_FILE_H 1

/* Define to 1 if you have the <sys/ioctl.h> header file. */
#define HAVE_SYS_IOCTL_H 1

/* Define to 1 if you have the <sys/mman.h> header file. */
#define HAVE_SYS_MMAN_H 1

/* Define to 1 if you have the <sys/param.h> header file. */
#define HAVE_SYS_PARAM_H 1

/* Define to 1 if you have the <sys/resource.h> header file. */
#define HAVE_SYS_RESOURCE_H 1

/* Define to 1 if you have the <sys/socket.h> header file. */
#define HAVE_SYS_SOCKET_H 1

/* Define to 1 if you have the <sys/stat.h> header file. */
#define HAVE_SYS_STAT_H 1

/* Define to 1 if you have the <sys/time.h> header file. */
#define HAVE_SYS_TIME_H 1

/* Define to 1 if you have the <sys/types.h> header file. */
#define HAVE_SYS_TYPES_H 1

/* Define to 1 if you have the <sys/un.h> header file. */
#define HAVE_SYS_UN_H 1

/* Define to 1 if you have the <sys/wait.h> header file. */
#define HAVE_SYS_WAIT_H 1

/* Define to 1 if you have the <unistd.h> header file. */
#define HAVE_UNISTD_H 1

/* Define to 1 if you have the `unsetenv' function. */
#define HAVE_UNSETENV 1

/* Define to 1 if you have the `vsyslog' function. */
#define HAVE_VSYSLOG 1

/* have zlib compression support */
#define HAVE_ZLIB 1

/* Define to 1 if you have the <zlib.h> header file. */
#define HAVE_ZLIB_H 1

/* Location of lzo1x.h */
#define LZO1X_H <lzo/lzo1x.h>

/* Name of package */
#define PACKAGE "tinc"

/* Define to the address where bug reports for this package should be sent. */
#define PACKAGE_BUGREPORT ""

/* Define to the full name of this package. */
#define PACKAGE_NAME "tinc"

/* Define to the full name and version of this package. */
#define PACKAGE_STRING "tinc UNKNOWN"

/* Define to the one symbol short name of this package. */
#define PACKAGE_TARNAME "tinc"

/* Define to the home page for this package. */
#define PACKAGE_URL ""

/* Define to the version of this package. */
#define PACKAGE_VERSION "UNKNOWN"

/* Define as the return type of signal handlers (`int' or `void'). */
#define RETSIGTYPE void

/* Define to 1 if you have the ANSI C header files. */
#define STDC_HEADERS 1

/* Enable extensions on AIX 3, Interix.  */
#ifndef _ALL_SOURCE
# define _ALL_SOURCE 1
#endif
/* Enable GNU extensions on systems that have them.  */
#ifndef _GNU_SOURCE
# define _GNU_SOURCE 1
#endif
/* Enable threading extensions on Solaris.  */
#ifndef _POSIX_PTHREAD_SEMANTICS
# define _POSIX_PTHREAD_SEMANTICS 1
#endif
/* Enable extensions on HP NonStop.  */
#ifndef _TANDEM_SOURCE
# define _TANDEM_SOURCE 1
#endif
/* Enable general extensions on Solaris.  */
#ifndef __EXTENSIONS__
# define __EXTENSIONS__ 1
#endif


/* Version number of package */
#define VERSION "UNKNOWN"

/* Define to 1 if on MINIX. */
/* #undef _MINIX */

/* Define to 2 if the system does not provide POSIX.1 features except with
   this defined. */
/* #undef _POSIX_1_SOURCE */

/* Define to 1 if you need to in order for `stat' and other things to work. */
/* #undef _POSIX_SOURCE */

/* Enable BSD extensions */
#define __USE_BSD 1

/* Defined if the __malloc__ attribute is not supported. */
/* #undef __malloc__ */

/* Defined if the __warn_unused_result__ attribute is not supported. */
/* #undef __warn_unused_result__ */
