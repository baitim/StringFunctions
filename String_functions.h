#ifndef STRING_FUNCTIONS_H
#define STRING_FUNCTIONS_H

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

const int MAX_SIZE = 1000;

int puts_(const char *s);

char *strchr_(const char *s, const int ch);

size_t strlen_(const char *s);

char *strcpy_(char *s, const char *t);

char *strncpy_(char *s, const char *t, const int n);

char *strcat_(char *s, const char *t);

char *strncat_(char *s, const char *t, const int n);

char *fgets_(char *s, const int n, FILE *stream);

char *strdup_(const char *s);

size_t getline_(char **s, size_t *n, FILE *stream);

char *strstr_(const char *s, const char *t);

#endif // STRING_FUNCTIONS_H
