/*
 * strcatz.c
 */

#include <stdarg.h>
#include <stdlib.h>
#include <string.h>

#include "stringz.h"


char *strcatz(const char *s, ...) {
	unsigned long int maxLen = sBufferIncrementz;
	unsigned long int len = 0UL;
	char *rr;
	char *r;
	char *p;
	const char *v;
	const char *g;
	if ((r = malloc(maxLen)) == NULL) {
		return(NULL);
	}
	va_list vl;
	va_start(vl, s);
	v = s;
	p = r;
	while (v) {
		g = v;
		while (*g) {
			*p++ = *g++;
			len++;
			if (len == maxLen) {
				maxLen += sBufferIncrementz;
				if ((rr = realloc(r, maxLen)) == NULL) {
					free(r);
					return(NULL);
				}
				r = rr;
				p = r + len;
			}
		}
		v = va_arg(vl, char *);
	}
	*p = 0;
	len++;
	if ((rr = realloc(r, len)) != NULL) {
		r = rr;
	}
	return(r);
}

