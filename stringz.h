/*
 * stringz.h
 */

#ifndef STRINGZ_H
#define STRINGZ_H


/*
 * GLOBAL DATA
 */

/*
 * sBufferIncrementz
 *
 * Functions that need to allocate memory for a result do so in chunks of
 * sBufferIncrementz size. As the buffer fills up, the size of it is further 
 * increased by this size. Once the function has completed and is ready to 
 * return a result, the size of the buffer is reduced to the size of the content
 * + the terminating null. This increment defaults to 4k, but can be changed at 
 * any time by the user.
 */
extern unsigned long int sBufferIncrementz;


/*
 * GLOBAL FUNCTIONS
 */

/*
 * strcatz
 *
 * Concatenates all strings in the variable-length parameter list and returns
 * the single concatenated string. The final parameter must be a NULL.
 */
extern char *strcatz(const char *s, ...);

/*
 * strcombz
 *
 * Returns all unique combinations of the given array of strings (a) (including 
 * the empty set). No particular ordering of the elements should be assumed. As
 * an example, given the following array of strings:
 *
 *	{"a", "b", "c", NULL}
 *
 * This function will return an array containing the following strings:
 *
 *  {"", "a", "b", "c", "ab", "ac", "bc", "abc", NULL}
 *
 * The last element of the input array should be NULL to mark the end of the 
 * array. The last element of the output array is NULL to mark the end of that
 * array. If the number of elements in the input array exceeds sizeof(unsigned
 * long long) * 8 (the number of bits in an unsigned long long), the function 
 * will return NULL without doing anything. The array returned by this function 
 * should be freed by the caller.
 *
 * If the input array is NULL, or a memory block could not be allocated, this 
 * function returns NULL.
 */
extern char **strcombz(const char **a);

/*
 * strfillz
 *
 * Returns a string consisting of a specified number of repititions (r) of an 
 * input string (s). The returned string must be freed by the caller. If the
 * input string is NULL, or a block of memory could not be allocated, this
 * function returns NULL.
 */
extern char *strfillz(const char *s, unsigned long int r);

/*
 * strlistz
 *
 * Takes any number of strings as parameters, terminated with a NULL parameter
 * and returns an array of pointers to those strings, with the final entry in
 * the array being a NULL pointer. The string returned by this function should
 * be freed by the caller. If the first string, s, is NULL, the function will 
 * return an array with one element containing a NULL pointer. If memory could 
 * not be allocated, a NULL is returned.
 */
extern char **strlistz(const char *s, ...);

/*
 * strmergez
 *
 * Merges an array of strings (a), separated by a delimiter string (s). The
 * string array must end with a NULL value, to mark the end of the array. If
 * the delimiter is NULL or empty, the values in the input array will be
 * merged with no separation. Empty strings in the input will still cause a 
 * non-empty delimiter to be inserted between them. If the input array is
 * NULL, or memory for the result cannot be allocated, NULL is returned. The
 * pointer returned by this function must be freed by the caller.
 */
extern char *strmergez(const char **a, const char *s);

/*
 * strrevz
 *
 * Reverses a string (s). If the input string is NULL or memory for the result
 * cannot be allocated, NULL is returned. The pointer returned by this function
 * should be freed by the caller.
 */
extern char *strrevz(const char *s);

/* 
 * strsplitz
 *
 * Splits a string (s) into multiple substrings, given a delimiter string (d). 
 * The result is returned as an array of pointers to the substrings. The
 * end of the array is marked with a NULL. If the delimiter is not in the 
 * string, an array of length two will be returned: the first element 
 * pointing to a copy of the entire input string and the last element NULL, 
 * marking the end of the array. If the input string is empty, an array of
 * length two will be returned: the first element pointing to the empty string 
 * and the last element NULL, marking the end of the array. A delimiter 
 * string at the first or last position of the input string will result in
 * an empty string as the first or last strings in the output array, 
 * respectively. Given an input string of "|", and a delimiter of '|', an
 * array of two empty strings and the NULL terminator will be returned. If the
 * delimiter is NULL or an empty string, each character of the input string will
 * be split out into a separate string. The array returned by this function 
 * should be freed by the caller when finished. If the input string s is NULL
 * or memory for the result could not be allocated, NULL is returned.
 */
extern char **strsplitz(const char *s, const char *d);

/*
 * strtrimz
 *
 * Removes whitespace from the beginning and end of the input string (s) and
 * returns the result as a new string, which must be freed by the caller when
 * finished. If the input string is all whitespace, an empty string will be
 * returned. A string with no leading or trailing whitespace--including an
 * empty string--will be returned unmodified. If the input string is NULL,
 * or memory for the result could not be allocated, the function returns
 * NULL.
 */
extern char *strtrimz(const char *s);

/*
 * strtruncz
 *
 * Removes the end of an input string (s), beginning with the first occurrence
 * of a specified delimiter string (d). If s or d are empty, or d is NULL, an
 * empty string is returned. If the input string s is empty, an empty string
 * is returned. If s is NULL, or memory for the result could not be allocated,
 * NULL is returned. The caller should free the pointer returned by this 
 * function when appropriate.
 */
extern char *strtruncz(const char *s, const char *d);


#endif /* STRINGZ_H */
