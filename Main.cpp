#include "ANSI_colors.h"

#include <stdio.h>
#include <stdlib.h>

const int MAX_SIZE = 1000;

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

int main ()
{
        printf(ANSI_LIGHT_BLUE "# Implementation of string functions\n"
                               "# (c) BAIDIUSENOV TIMUR, 2023\n\n" ANSI_DEFAULT_COLOR);

        puts_("yes");

        char *s1 = strchr_("abcdef", 'c');

        printf("%d\n", s1 - "abcdef" + 1);

        int n = strlen_("github?");

        printf("%d\n", n);

        char s2[MAX_SIZE] = "";

        printf("%s\n", strcpy_(s2, "qwerty"));

        char s3[MAX_SIZE] = "";

        printf("%s\n", strncpy_(s3, "abcdefg", 4));

        char s4[MAX_SIZE] = "abc";

        printf("%s\n", strcat_(s4, "edf"));

        char s5[MAX_SIZE] = "asd";

        printf("%s\n", strncat_(s5, "fghjk", 2));

        char s6[MAX_SIZE] = "";
        FILE *test_fgets_ = fopen("test_fgets_.txt", "r");

        printf("%s\n", fgets_(s6, 6, test_fgets_));

        char s7[MAX_SIZE] = "poltorashka";

        printf("%s\n", strdup_(s7));

        printf(ANSI_LIGHT_GREEN "Input string: " ANSI_DEFAULT_COLOR);

        char s8[MAX_SIZE] = "";

        printf("%d\n", getline_(s8, 1000));

        char s9[MAX_SIZE] = "1234567890";

        printf("%s\n", strstr_(s9, "456"));

        return 0;
}

int puts_(const char *s)
{
        if (s == NULL)
                return EOF;

        int i = 0;

        while (s[i]) {
                if (putchar(s[i]) == EOF)
                        return EOF;
                i++;
        }

        if (putchar('\n') == EOF)
                return EOF;

        return 1;
}

char *strchr_(const char *s, const int ch)
{
        if (s == NULL)
                return NULL;

        if ((ch > 255) || (ch < 0))
                return NULL;

        int i = 0;

        while (s[i]) {
                if (s[i] == ch)
                        return const_cast<char *>(&s[i]);
                i++;
        }

        return NULL;
}

size_t strlen_(const char *s)
{
        int i = 0;
        while (s[i] != '\0')
                i++;

        return i;
}

char *strcpy_(char *s, const char *t)
{
        int i = 0;

        while ((s[i] = t[i]) != '\0')
                i++;

        s[i+1] = '\0';

        return s;
}

char *strncpy_(char *s, const char *t, const int n)
{
        int i = 0;

        while ((i < n) && ((s[i] = t[i]) != '\0'))
                i++;

        while (i < n) {
                s[i] = '\0';
                i++;
        }

        return s;
}

char *strcat_(char *s, const char *t)
{
        int i = 0;
        int j = 0;

        while (s[i] != '\0')
                i++;

        while ((s[i] = t[j]) != '\0') {
                i++;
                j++;
        }

        s[i+1] = '\0';

        return s;
}

char *strncat_(char *s, const char *t, const int n)
{
        int i = 0;
        int j = 0;

        while (s[i] != '\0')
                i++;

        while ((j < n) && ((s[i] = t[j]) != '\0')) {
                i++;
                j++;
        }

        s[i+1] = '\0';

        return s;
}

char *fgets_(char *s, const int n, FILE *stream)
{
        int i = 0;
        int c = 0;

        while (i < n-1) {
                if ((c = getc(stream)) == EOF)
                        return NULL;

                if ((s[i] = char(c)) == '\n')
                        break;

                i++;
        }

        s[i+1] = '\0';

        return s;
}

char *strdup_(char *s)
{
        char *p;
        p = (char *) malloc(strlen_(s) + 1);

        if (p == NULL)
                return NULL;

        strcpy_(p, s);
        return p;
}

size_t getline_(char *s, const int n)
{
        return (fgets_(s, n, stdin)) ? strlen_(s) : NULL;
}

char *strstr_(const char *s, const char *t)
{
        int i = 0;
        int j = 0;

        while (s[i]) {
                if (s[i] != t[j])
                        j = 0;
                else
                        j++;

                if (!t[j])
                        return const_cast<char *>(&s[i - j + 1]);

                i++;
        }

        return NULL;
}
