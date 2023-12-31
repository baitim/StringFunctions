#include "ANSI_colors.h"
#include "Check_runtime.h"
#include "String_functions.h"
#include "Tests.h"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main ()
{
        printf(ANSI_LIGHT_BLUE "# Implementation of string functions\n"
                               "# (c) BAIDIUSENOV TIMUR, 2023\n\n" ANSI_DEFAULT_COLOR);

#ifdef RUNTIME_TEST_ON
        runtime_test();
#endif

#ifdef TEST_ON
        test();
#endif

        printf(ANSI_LIGHT_BLUE "Bye\n" ANSI_DEFAULT_COLOR);

        return 0;
}
