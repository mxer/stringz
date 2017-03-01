/*
 * strtruncz.c
 */

#include <string.h>
#include <stdlib.h>

#include "stringz.h"


char *strtruncz(const char *s, const char *d) {
	if (s == NULL) {
		return(NULL);
	}
	if (d == NULL || *d == 0) {
		char *t = malloc(1);
		if (t == NULL) {
			return(NULL);
		}
		*t = 0;
		return(t);
	}
	const char *a = strstr(s, d);
	if (a == NULL) {
		return(strdup(s));
	}
	char *b = malloc((a - s) + 1);
	char *c = b;
	if (b == NULL) {
		return(NULL);
	}
	while (s != a) {
		*c++ = *s++;
	}
	*c = 0;
	return(b);
}
