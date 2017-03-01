/*
 * strfillz.c
 */

#include <stdlib.h>
#include <string.h>

#include "stringz.h"


char *strfillz(const char *s, unsigned long int r) {
	if (s == NULL) {
		return(NULL);
	}
	unsigned long int maxLen = sBufferIncrementz;
	unsigned long int len = 0UL;
	char *nn = NULL;
	char *n = NULL;
	const char *o;
	if ((n = malloc(maxLen)) == NULL) {
		return(NULL);
	}
	char *t = n;
	while (r--) {
		o = s;
		while (*o) {
			*t++ = *o++;
			len++;
			if (len == maxLen) {
				maxLen += sBufferIncrementz;
				if ((nn = realloc(n, maxLen)) == NULL) {
					free(n);
					return(NULL);
				}
				n = nn;
				t = n + len;
			}
		}
	}
	*t = 0;
	len++;
	if ((nn = realloc(n, maxLen)) != NULL) {
		n = nn;
	}
	return(n);
}
