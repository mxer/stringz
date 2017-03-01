/*
 * strmergez.c
 */

#include <string.h>
#include <stdlib.h>

#include "stringz.h"


char *strmergez(const char **a, const char *d) {
	if (a == NULL) {
		return(NULL);
	}
	if (d == NULL) {
		d = "";
	}
	unsigned long int maxLen = sBufferIncrementz;
	unsigned long int len = 0UL;
	char *rr = NULL;
	char *r = NULL;
	char *t = NULL;
	if ((r = malloc(maxLen)) == NULL) {
		return(NULL);
	}
	t = r;
	while (*a) {
		const char *s = *a;
		while (*s) {
			*t++ = *s++;
			len++;
			if (len == maxLen) {
				maxLen += sBufferIncrementz;
				if ((rr = realloc(r, maxLen)) == NULL) {
					free(r);
					return(NULL);
				}
				r = rr;
				t = r + len;
			}
		}
		if (a[1] == NULL) {
			break;
		}
		s = d;
		while (*s) {
			*t++ = *s++;
			len++;
			if (len == maxLen) {
				maxLen += sBufferIncrementz;
				if ((rr = realloc(r, maxLen)) == NULL) {
					free(r);
					return(NULL);
				}
				r = rr;
				t = r + len;
			}
		}
		a++;
	}
	*t = 0;
	len++;
	if ((rr = realloc(r, len)) != NULL) {
		r = rr;
	}
	return(r);
}
