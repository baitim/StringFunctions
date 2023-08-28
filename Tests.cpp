#include "ANSI_colors.h"
#include "String_functions.h"
#include "Tests.h"

#ifdef TEST_ON

void test()
{
        test_puts_();

        test_strchr_();

        /*test_strlen_();

        test_strcpy_();

        test_strncpy_();

        test_strcat_();

        test_strncat_();

        test_fgets_();

        test_strdup();

        test_getline_();

        test_strstr_();*/
}

void test_puts_()
{
        puts_(ANSI_LIGHT_GREEN "puts_ OK" ANSI_DEFAULT_COLOR);
        puts_(ANSI_LIGHT_GREEN "puts_ OK" ANSI_DEFAULT_COLOR);

        printf("\n");
}

void test_strchr_()
{
        const char *st = "abcdefgh";

        int test1 = strchr_(st, 'c') - st + 1;
        int test1_ref = 3;

        int test2 = strchr_(st, 'f') - st + 1;
        int test2_ref = 6;

        if (test1 == test1_ref)
                printf(ANSI_LIGHT_GREEN "test_strchr_ OK\n" ANSI_DEFAULT_COLOR);
        else
                printf(ANSI_LIGHT_RED "test_strchr_ ERROR: expected %d, answer: %d\n" ANSI_DEFAULT_COLOR,
                                      test1_ref, test1);

        if (test2 == test2_ref)
                printf(ANSI_LIGHT_GREEN "test_strchr_ OK\n" ANSI_DEFAULT_COLOR);
        else
                printf(ANSI_LIGHT_RED "test_strchr_ ERROR: expected %d, answer: %d\n" ANSI_DEFAULT_COLOR,
                                      test1_ref, test1);

        printf("\n");
}

#endif // TEST_ON
