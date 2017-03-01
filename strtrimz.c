/*
 * strtrimz.c
 *
 * strip whitespace from the begin and end of a string, in place.
 */

#include <ctype.h>
#include <string.h>

#include "stringz.h"


char *strtrimz(const char *s) {
	if (s == NULL) {
		return(NULL);
	}
	char *d;
	char *r;
	const char *e = s + strlen(s) - 1;
	while (isspace(*s)) s++;
	while (isspace(*e) && e > s) e--;
	e++;
	d = r = malloc((unsigned long)e - (unsigned long)s + 1L);
	if (d == NULL) {
		return(NULL);
	}
	while (s < e) {
		*d++ = *s++;
	}
	*d = 0;
	return(r);
}
