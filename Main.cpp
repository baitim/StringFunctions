#include "ANSI_colors.h"
#include "String_functions.h"
#include "Tests.h"

#include <stdio.h>
#include <stdlib.h>

int main ()
{
        printf(ANSI_LIGHT_BLUE "# Implementation of string functions\n"
                               "# (c) BAIDIUSENOV TIMUR, 2023\n\n" ANSI_DEFAULT_COLOR);

#ifdef TEST_ON
        test();
#endif

        printf(ANSI_LIGHT_GREEN "Input string: " ANSI_DEFAULT_COLOR);

        char s8[MAX_SIZE] = "";

        printf("%d\n", getline_(s8, 1000));

        char s9[MAX_SIZE] = "1234567890";

        printf("%s\n", strstr_(s9, "456"));

        return 0;
}
