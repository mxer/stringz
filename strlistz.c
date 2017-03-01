/*
 * strlistz.c
 */

#include <stdarg.h>
#include <stdlib.h>
#include <string.h>

#include "stringz.h"


char **strlistz(const char *s, ...) {
	char **rr = NULL;
	char **r = NULL;
	va_list ap;
	unsigned long int argsPerIncrement = sBufferIncrementz / sizeof(char *);
	unsigned long int maxArgs = argsPerIncrement;
	unsigned long int numArgs = 0UL;
	if ((r = malloc(maxArgs * sizeof(char *))) == NULL) {
		return(NULL);
	}
	const char *p = s;
	va_start(ap, s);
	while (p) {
		r[numArgs++] = (char *)p;
		if (numArgs == maxArgs) {
			maxArgs += argsPerIncrement;
			if ((rr = realloc(r, maxArgs * sizeof(char *))) == NULL) {
				free(r);
				va_end(ap);
				return(NULL);
			}
			r = rr;
		}
		p = va_arg(ap, char *);
	}
	va_end(ap);
	r[numArgs++] = NULL;
	return(r);
	if ((rr = realloc(r, numArgs * sizeof(char *))) != NULL) {
		r = rr;
	}
	return(r);
}
