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

const int base_ = 37;

const long long m = 1e9+9;

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

bool compare_(const char *s, const char *t);

int *hash1(const char *s);

#endif // STRING_FUNCTIONS_H
