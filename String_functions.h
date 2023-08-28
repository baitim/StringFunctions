#ifndef STRING_FUNCTIONS_H
#define STRING_FUNCTIONS_H

#include <stdio.h>
#include <stdlib.h>

int puts_(const char *s);

char *strchr_(const char *s, const int ch);

size_t strlen_(const char *s);

char *strcpy_(char *s, const char *t);

char *strncpy_(char *s, const char *t, const int n);

char *strcat_(char *s, const char *t);

char *strncat_(char *s, const char *t, const int n);

char *fgets_(char *s, const int n, FILE *stream);

char *strdup_(char *s);

size_t getline_(char *s, const int n);

char *strstr_(const char *s, const char *t);

#endif // STRING_FUNCTIONS_H
