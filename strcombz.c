/*
 * strcombz.c
 */

#include <stdlib.h>
#include <string.h>

#include "stringz.h"


char **strcombz(const char **a) {
	if (a == NULL) {
		return(NULL);
	}
	unsigned long long i;
	unsigned long long j;
	unsigned long long b = 1LL;
	unsigned long elems = 0LL;
	unsigned long max = 0LL;
	char **p = (char **)a;
	char **d;
	char *s;
	char *t;
	const char *u;
	while (*p) {
		i = strlen(*p);
		if (i > max) {
			max = i;
		}
		elems++;
		p++;
	}
	if (elems > sizeof(unsigned long long) * 8) {
		return(NULL);
	}
	max = max * elems + 1LL;
	s = malloc((((1LL << elems) + 1) * (unsigned long long)sizeof(char *)) + (unsigned long long)(max * (1LL << elems)));
	if (s == NULL) {
		return(NULL);
	}
	d = (char **)s;
	s += (unsigned long long)(((1LL << elems) + 1) * sizeof(char *));
	t = s;
	for (i = 0; i < 1LL << elems; i++) {
		d[i] = t;
		for (j = 0; j < elems; j++) {
			if (i & (1 << j)) {
				u = a[j];
				while (*u) {
					*t++ = *u++;
				}
			}
		}
		*t++ = 0;
	}
	d[i] = 0;
	return(d);
}
