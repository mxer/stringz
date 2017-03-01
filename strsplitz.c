/*
 * strsplitz.c
 *
 * split a string into an array of strings, using a given delimiter string.
 */

#include <stdlib.h>
#include <string.h>

#include "stringz.h"


char **strsplitz(const char *s, const char *d) {
	if (s == NULL) {
		return(NULL);
	}
	if (d == NULL) {
		d = "";
	}
	unsigned long dlen = strlen(d);
	unsigned long len = strlen(s) + 1;
	unsigned long max_subs = len;
	unsigned long sub = 0;
	unsigned long i;
	char *str = (char *)(max_subs * sizeof(char *));
	char *mem = malloc((unsigned long)str + len * 2);
	if (mem == NULL) {
		return(NULL);
	}
	str += (unsigned long)mem;
	char *t = str;
	if (dlen == 0) {
		for (i = 0; s[i]; i++) {
			((char **)mem)[sub++] = t;
			*t++ = s[i];
			*t++ = 0;
		}
	} else {
		i = 0;
		while (1) {
			if (!strncmp(s + i, d, dlen) || s[i] == 0) {
				((char **)mem)[sub++] = t;
				*str = 0;
				if (s[i] == 0) {
					break;
				}
				t = str + 1;
				i += dlen;
			} else {
				*str = s[i++];
			}
			str++;
		}
	}
	((char **)mem)[sub] = NULL;
	return((char **)mem);
}
