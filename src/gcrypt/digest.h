#ifndef TINC_GCRYPT_DIGEST_H
#define TINC_GCRYPT_DIGEST_H

/*
    digest.h -- header file digest.c
    Copyright (C) 2007-2009 Guus Sliepen <guus@tinc-vpn.org>

    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License along
    with this program; if not, write to the Free Software Foundation, Inc.,
    51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
*/

#include <gcrypt.h>

#define DIGEST_MAX_SIZE 64

typedef struct digest {
	int algo;
	int nid;
	int maclength;
	gcry_md_hd_t hmac;
} digest_t;

extern bool digest_open_by_name(struct digest *, const char *name, int maclength);
extern bool digest_open_by_nid(struct digest *, int nid, int maclength);
extern bool digest_open_sha1(struct digest *, int maclength);
extern void digest_close(struct digest *);
extern bool digest_create(struct digest *, const void *indata, size_t inlen, void *outdata);
extern bool digest_verify(struct digest *, const void *indata, size_t inlen, const void *digestdata);
extern bool digest_set_key(struct digest *, const void *key, size_t len);
extern int digest_get_nid(const struct digest *);
extern size_t digest_length(const struct digest *);
extern bool digest_active(const struct digest *);

#endif
