/*
 * main.c
 *
 * stringz test program.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "stringz.h"


static void demoCombs(void);
static void demoFill(void);
static void demoList(void);
static void demoMerge(void);
static void demoReverse(void);
static void demoSplit(void);
static void demoTrim(void);
static void demoTrunc(void);


int main(int ac, char **av) {
	sBufferIncrementz = 5;
	demoCombs();
	demoFill();
	demoList();
	demoMerge();
	demoReverse();
	demoSplit();
	demoTrim();
	demoTrunc();
}


static void demoCombs(void) {
	const char *a[] = {
		"a",
		"b",
		"c",
		"d",
		NULL
	};
	char **p = (char **)a;
	printf("original strings: ");
	while (*p) {
		printf("[%s] ", *p);
		p++;
	}
	printf("\n");
	p = strcombz(a);
	char **i = p;
	printf("after strcombz: ");
	while (*i) {
		printf("[%s] ", *i);
		i++;
	}
	printf("\n");
	free(p);
}


static void demoFill(void) {
	printf("calling: strfillz(\"abc\", 10);\n");
	char *s = strfillz("abc", 10);
	printf("after strfillz: [%s]\n", s);
	free(s);
	printf("calling: strfillz(\"\", 10);\n");
	s = strfillz("", 10);
	printf("after strfillz: [%s]\n", s);
	free(s);
	printf("calling: strfillz(\"*\", 0);\n");
	s = strfillz("*", 0);
	printf("after strfillz: [%s]\n", s);
	free(s);
}


static void demoList(void) {
	printf("calling: strlistz(\"this\", \"is\", \"a\", \"test\", NULL);\n");
	char **p = strlistz("this", "is", "a", "test", NULL);
	char **s = p;
	printf("result:\n");
	while (*s) {
		printf("[%s]\n", *s);
		s++;
	}
	free(p);
	printf("calling: strlistz(NULL);\n");
	p = strlistz(NULL);
	s = p;
	printf("result:\n");
	while (*s) {
		printf("[%s]\n", *s);
		s++;
	}
	free(p);
	printf("calling strlistz(\"stdin\", NULL);\n");
	p = strlistz("stdin", NULL);
	s = p;
	printf("result:\n");
	while (*s) {
		printf("[%s]\n", *s);
		s++;
	}
	free(p);
}


static void demoMerge(void) {
	char *a[] = {
		"this",
		"is",
		"a",
		"test",
		"string!",
		NULL
	};
	char **p = (char **)a;
	printf("original strings: ");
	while (*p) {
		printf("[%s] ", *p);
		p++;
	}
	printf("\n");
	char *s = strmergez((const char **)a, " ");
	printf("after strmergez: [%s]\n", s);
	free(s);
}


static void demoReverse(void) {
	char *s = "This is a test!";
	printf("original string: [%s]\n", s);
	s = strrevz(s);
	printf("after strrevz: [%s]\n", s);
	free(s);
}


static void demoSplit(void) {
	/* test 1 */
	char *s = "this is a test string!";
	char **a = strsplitz(s, " ");
	char **p = a;
	printf("original string: [%s]\n", s);
	printf("after strsplitz: ");
	while (*p) {
		printf("[%s] ", *p++);
	}
	printf("\n");
	free(a);
	/* test 2 */
	s = "this is a test string!";
	a = strsplitz(s, "");
	p = a;
	printf("original string: [%s]\n", s);
	printf("after strsplitz: ");
	while (*p) {
		printf("[%s] ", *p++);
	}
	printf("\n");
	free(a);
	/* test 3 */
	s = "";
	a = strsplitz(s, "del");
	p = a;
	printf("original string: [%s]\n", s);
	printf("after strsplitz: ");
	while (*p) {
		printf("[%s] ", *p++);
	}
	printf("\n");
	free(a);
}


static void demoTrim(void) {
	char *s = "    this is a test string!    ";
	printf("original string: [%s]\n", s);
	s = strtrimz(s);
	printf("after strtrimz: [%s]\n", s);
	free(s);
}


static void demoTrunc(void) {
	char *s = "this is a test string!  ; this is some more junk to remove!";
	printf("original string: [%s]\n", s);
	s = strtruncz(s, ";");
	printf("after strtruncz: [%s]\n", s);
	free(s);
	s = "this is a test string!  ; this is some more junk to remove!";
	printf("original string: [%s]\n", s);
	s = strtruncz(s, "");
	printf("after strtruncz with an empty delimiter: [%s]\n", s);
	free(s);
	s = "this is a test string!  ; this is some more junk to remove!";
	printf("original string: [%s]\n", s);
	s = strtruncz(s, NULL);
	printf("after strtruncz with null delimiter: [%s]\n", s);
	free(s);
	s = "";
	printf("original string: [%s]\n", s);
	s = strtruncz(s, ";");
	printf("after strtruncz with a [;] delimiter: [%s]\n", s);
	free(s);
}

