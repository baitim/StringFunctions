#include "ANSI_colors.h"

#include <stdio.h>

int puts_(const char *s);

char *strchr_(const char *s, int ch);

int strlen_(const char *s);

int main ()
{
        printf(ANSI_LIGHT_BLUE "# Implementation of string functions\n"
                               "# (c) BAIDIUSENOV TIMUR, 2023\n\n" ANSI_DEFAULT_COLOR);

        puts_("ABOBA 45");
        puts_("ABOBA 45");

        char *s = strchr_("abcdef", 'c');

        printf("%d\n", s - "abcdef" + 1);

        int n = strlen_("github?");

        printf("%d\n", n);

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

char *strchr_(const char *s, int ch)
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
