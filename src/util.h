/*
 *  This file is a part of libacars
 *
 *  Copyright (c) 2018 Tomasz Lemiech <szpajder@gmail.com>
 *
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#ifndef _LA_UTIL_H
#define _LA_UTIL_H 1
#include <stdio.h>
#include <stdint.h>

typedef struct {
	uint8_t id;
	void *val;
} la_dict;

#define la_debug_print(fmt, ...) \
	do { if (DEBUG) fprintf(stderr, "%s(): " fmt, __func__, __VA_ARGS__); } while (0)

#define la_debug_print_buf_hex(buf, len, fmt, ...) \
	do { \
		if (DEBUG) { \
			fprintf(stderr, "%s(): " fmt, __func__, __VA_ARGS__); \
			fprintf(stderr, "%s(): ", __func__); \
			for(int zz = 0; zz < (len); zz++) { \
				fprintf(stderr, "%02x ", buf[zz]); \
				if(zz && (zz+1) % 32 == 0) fprintf(stderr, "\n%s(): ", __func__); \
			} \
			fprintf(stderr, "\n"); \
		} \
	} while(0)

#define LA_XCALLOC(nmemb, size) la_xcalloc((nmemb), (size), __FILE__, __LINE__, __func__)
#define LA_XREALLOC(ptr, size) la_xrealloc((ptr), (size), __FILE__, __LINE__, __func__)
#define LA_XFREE(ptr) do { free(ptr); ptr = NULL; } while(0)

void *la_xcalloc(size_t nmemb, size_t size, const char *file, const int line, const char *func);
void *la_xrealloc(void *ptr, size_t size, const char *file, const int line, const char *func);
void *la_dict_search(const la_dict *list, uint8_t id);
size_t la_slurp_hexstring(char *string, uint8_t **buf);
#endif // !_LA_UTIL_H