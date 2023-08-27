#include "ANSI_colors.h"

#include <stdio.h>

const int MAX_SIZE = 1000;

int puts_(const char *s);

char *strchr_(const char *s, const int ch);

int strlen_(const char *s);

char *strcpy_(char *s, const char *t);

char *strncpy_(char *s, const char *t, const int n);

char *strcat_(char *s, const char *t);

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

int strlen_(const char *s)
{
        int i = 0;
        while (s[i])
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

        return s;
}
