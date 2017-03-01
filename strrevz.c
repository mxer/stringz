/*
 * strrevz.c
 */

#include <stdlib.h>
#include <string.h>

#include "stringz.h"


char *strrevz(const char *s) {
	if (s == NULL ) {
		return(NULL);
	}
	unsigned long int l = strlen(s);
	char *t = malloc(l + 1);
	if (t == NULL) {
		return(NULL);
	}
	s += l - 1;
	char *d = t;
	while (l) {
		*d++ = *s--;
		l--;
	}
	*d = 0;
	return(t);
}
