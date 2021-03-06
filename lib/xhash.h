/*
 * jabberd - Jabber Open Source Server
 * Copyright (c) 2002-2004 Jeremie Miller, Thomas Muldowney,
 *                         Ryan Eatmon, Robert Norris
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA02111-1307USA
 */

/** @file util/xhash.h
  * @brief hashtables
  */

#ifndef INCL_UTIL_XHASH_H
#define INCL_UTIL_XHASH_H 1

#include "util.h"

typedef struct _xht xht;

JABBERD2_API xht *xhash_new(int prime);
JABBERD2_API void xhash_put(xht *h, const char *key, void *val);
JABBERD2_API void xhash_putx(xht *h, const char *key, int len, void *val);
JABBERD2_API void *xhash_get(xht *h, const char *key);
JABBERD2_API void *xhash_getx(xht *h, const char *key, int len);
JABBERD2_API void xhash_zap(xht *h, const char *key);
JABBERD2_API void xhash_zapx(xht *h, const char *key, int len);
JABBERD2_API void xhash_stat(xht *h);
JABBERD2_API void xhash_free(xht *h);
typedef void (*xhash_walker)(const char *key, int keylen, void *val, void *arg);
JABBERD2_API void xhash_walk(xht *h, xhash_walker w, void *arg);
JABBERD2_API int xhash_count(xht *h);

/* iteration functions */
JABBERD2_API int xhash_iter_first(xht *h);
JABBERD2_API int xhash_iter_next(xht *h);
JABBERD2_API void xhash_iter_zap(xht *h);
JABBERD2_API int xhash_iter_get(xht *h, const char **key, int *keylen, void **val);

#endif
