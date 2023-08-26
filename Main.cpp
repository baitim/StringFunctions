#include "ANSI_colors.h"

#include <stdio.h>

int puts_(const char *string);

char *strchr_(const char *string, int ch);

int main ()
{
        printf(ANSI_LIGHT_BLUE "# Implementation of string functions\n"
                               "# (c) BAIDIUSENOV TIMUR, 2023\n\n" ANSI_DEFAULT_COLOR);

        puts_("ABOBA 45");
        puts_("ABOBA 45");

        char *s = strchr_("abcdef", 'c');

        printf("%d\n", s - "abcdef" + 1);

        return 0;
}

int puts_(const char *string)
{
        if (string == NULL)
                return EOF;

        int i = 0;

        while (string[i]) {
                if (putchar(string[i]) == EOF)
                        return EOF;
                i++;
        }

        if (putchar('\n') == EOF)
                return EOF;

        return 1;
}

char *strchr_(const char *string, int ch)
{
        if (string == NULL)
                return NULL;

        if ((ch > 255) || (ch < 0))
                return NULL;

        int i = 0;

        while (string[i]) {
                if (string[i] == ch)
                        return const_cast<char *>(&string[i]);
                i++;
        }

        return NULL;
}
