#include "ANSI_colors.h"
#include "String_functions.h"
#include "Tests.h"

#include <stdio.h>
#include <stdlib.h>

const int MAX_SIZE = 1000;

int main ()
{
        printf(ANSI_LIGHT_BLUE "# Implementation of string functions\n"
                               "# (c) BAIDIUSENOV TIMUR, 2023\n\n" ANSI_DEFAULT_COLOR);

#ifdef TEST_ON
        test();
#endif
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
