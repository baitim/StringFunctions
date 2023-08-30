#ifndef STRING_FUNCTIONS_H
#define STRING_FUNCTIONS_H

#include "ANSI_colors.h"

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

#ifndef NDEBUG
#define ASSERT(x)                                                       \
        if (!(x)) {                                                     \
                printf(ANSI_LIGHT_RED "Text in assert: (%s)\n", #x);    \
                printf("File: %s\n", __FILE__);                         \
                printf("Function: %s\n", __PRETTY_FUNCTION__);          \
                printf("Line: %d\n" ANSI_DEFAULT_COLOR, __LINE__);      \
                exit(0);                                                \
        }
#else
#define ASSERT(...)
#endif

const int MAX_SIZE = 1000;

const int BASE = 31;

const long long MOD = 1e9 + 9;

/*!
@brief Function writes every character from the null-terminated string.
@param[in] s character string to be written
*/
int puts_(const char *s);

/*!
@brief Function finds the first occurrence of ch.
@param[in] s pointer to the null-terminated byte string to be analyzed
@param[in] ch character to search for
*/
char *strchr_(const char *s, const int ch);

/*!
@brief Function returns the length of the given null-terminated byte string.
@param[in] s pointer to the null-terminated byte string to be examined
*/
size_t strlen_(const char *s);

/*!
@brief Function copies the null-terminated byte string.
@param[in] s pointer to the character array to write to
@param[in] t pointer to the null-terminated byte string to copy from
*/
char *strcpy_(char *s, const char *t);

/*!
@brief Function copies at most count characters of the character array pointed to by t.
@param[in] s null pointer
@param[in] t null pointer
@param[in] n maximum number of characters to copy
*/
char *strncpy_(char *s, const char *t, const int n);

/*!
@brief Function appends a copy of the null-terminated byte string pointed to by t to the end
        of the null-terminated byte string pointed to by s.
@param[in] s pointer to the null-terminated byte string to append to
@param[in] t pointer to the null-terminated byte string to copy from
*/
char *strcat_(char *s, const char *t);

/*!
@brief Function appends at most count characters from the character array pointed to by t, stopping if the null character is found.
@param[in] s pointer to the null-terminated byte string to append to
@param[in] t pointer to the character array to copy from
@param[in] n maximum number of characters to copy
*/
char *strncat_(char *s, const char *t, const int n);

char *fgets_(char *s, const int n, FILE *stream);

char *strdup_(const char *s);

ssize_t getline_(char **s, size_t *n, FILE *stream);

char *strstr_(const char *s, const char *t);

void hash_function(long long *x, long long *y, char ch);

int strncmp_(const char *s, const char *t, size_t count);

#endif // STRING_FUNCTIONS_H
