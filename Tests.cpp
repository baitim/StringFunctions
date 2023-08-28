#include "ANSI_colors.h"
#include "String_functions.h"
#include "Tests.h"

#include <string.h>

#ifdef TEST_ON

void test()
{
        test_puts_();

        test_strchr_();

        test_strlen_();

        test_strcpy_();

        test_strncpy_();

        test_strcat_();

        test_strncat_();

        test_fgets_();

        test_strdup_();

        test_getline_();

        test_strstr_();
}

void cmp_data_int(int test, int test_ref)
{
        if (test == test_ref)
                printf(ANSI_LIGHT_GREEN "TEST OK\n" ANSI_DEFAULT_COLOR);
        else
                printf(ANSI_LIGHT_RED "TEST ERROR: expected %d, answer: %d\n" ANSI_DEFAULT_COLOR,
                                      test_ref, test);
}

void cmp_data_char(char *test, char *test_ref)
{
        if (strcmp(test, test_ref) == 0)
                printf(ANSI_LIGHT_GREEN "TEST OK\n" ANSI_DEFAULT_COLOR);
        else
                printf(ANSI_LIGHT_RED "TEST ERROR: expected %s, answer: %s\n" ANSI_DEFAULT_COLOR,
                                      test_ref, test);
}

void test_puts_()
{
        printf(ANSI_LIGHT_YELLOW "PUTS_\n" ANSI_DEFAULT_COLOR);

        puts_(ANSI_LIGHT_GREEN "TEST OK" ANSI_DEFAULT_COLOR);
        puts_(ANSI_LIGHT_GREEN "TEST OK" ANSI_DEFAULT_COLOR);

        printf("\n");
}

void test_strchr_()
{
        printf(ANSI_LIGHT_YELLOW "STRCHR_\n" ANSI_DEFAULT_COLOR);

        const char *st = "abcdefgh";

        int test1 = strchr_(st, 'c') - st + 1;
        int test1_ref = 3;

        int test2 = strchr_(st, 'f') - st + 1;
        int test2_ref = 6;

        cmp_data_int(test1, test1_ref);
        cmp_data_int(test2, test2_ref);

        printf("\n");
}

void test_strlen_()
{
        printf(ANSI_LIGHT_YELLOW "STRLEN_\n" ANSI_DEFAULT_COLOR);

        int test1 = strlen_("1234567");
        int test1_ref = 7;

        int test2 = strlen_("1234");
        int test2_ref = 4;

        cmp_data_int(test1, test1_ref);
        cmp_data_int(test2, test2_ref);

        printf("\n");
}

void test_strcpy_()
{
        printf(ANSI_LIGHT_YELLOW "STRCPY_\n" ANSI_DEFAULT_COLOR);

        char test1_to_func[MAX_SIZE];
        char *test1 = strcpy_(test1_to_func, "1234567");
        char test1_ref[] = "1234567";

        char test2_to_func[MAX_SIZE];
        char *test2 = strcpy_(test2_to_func, "abcd");
        char test2_ref[] = "abcd";

        cmp_data_char(test1, test1_ref);
        cmp_data_char(test2, test2_ref);

        printf("\n");
}

void test_strncpy_()
{
        printf(ANSI_LIGHT_YELLOW "STRNCPY_\n" ANSI_DEFAULT_COLOR);

        char test1_to_func[MAX_SIZE];
        char *test1 = strncpy_(test1_to_func, "1234567", 5);
        char test1_ref[] = "12345";

        char test2_to_func[MAX_SIZE];
        char *test2 = strncpy_(test2_to_func, "abcd", 7);
        char test2_ref[] = "abcd";

        cmp_data_char(test1, test1_ref);
        cmp_data_char(test2, test2_ref);

        printf("\n");
}

void test_strcat_()
{
        printf(ANSI_LIGHT_YELLOW "STRCAT_\n" ANSI_DEFAULT_COLOR);

        char test1_to_func[MAX_SIZE] = "123";
        char *test1 = strcat_(test1_to_func, "4567");
        char test1_ref[] = "1234567";

        char test2_to_func[MAX_SIZE] = "";
        char *test2 = strcat_(test2_to_func, "abcd");
        char test2_ref[] = "abcd";

        cmp_data_char(test1, test1_ref);
        cmp_data_char(test2, test2_ref);

        printf("\n");
}

void test_strncat_()
{
        printf(ANSI_LIGHT_YELLOW "STRNCAT_\n" ANSI_DEFAULT_COLOR);

        char test1_to_func[MAX_SIZE] = "123";
        char *test1 = strncat_(test1_to_func, "4567", 2);
        char test1_ref[] = "12345";

        char test2_to_func[MAX_SIZE] = "";
        char *test2 = strncat_(test2_to_func, "abcd", 7);
        char test2_ref[] = "abcd";

        cmp_data_char(test1, test1_ref);
        cmp_data_char(test2, test2_ref);

        printf("\n");
}

void test_fgets_()
{
        printf(ANSI_LIGHT_YELLOW "FGETS_\n" ANSI_DEFAULT_COLOR);

        FILE *test_fgets_ = fopen("Tests.txt", "r");

        char test1_to_func[MAX_SIZE] = "";
        char *test1 = fgets_(test1_to_func, 6, test_fgets_);
        char test1_ref[] = "123\n";

        char test2_to_func[MAX_SIZE] = "";
        char *test2 = fgets_(test2_to_func, 5, test_fgets_);
        char test2_ref[] = "abcd";

        cmp_data_char(test1, test1_ref);
        cmp_data_char(test2, test2_ref);

        printf("\n");
}

void test_strdup_()
{
        printf(ANSI_LIGHT_YELLOW "STRDUP_\n" ANSI_DEFAULT_COLOR);

        char *test1 = strdup_("1234");
        char test1_ref[] = "1234";

        char *test2 = strdup_("abcdef");
        char test2_ref[] = "abcdef";

        cmp_data_char(test1, test1_ref);
        cmp_data_char(test2, test2_ref);

        printf("\n");
}

void test_getline_()
{
        printf(ANSI_LIGHT_YELLOW "GETLINE_\n" ANSI_DEFAULT_COLOR);

        FILE *test_fgets_ = fopen("Tests.txt", "r");

        char test1_to_func[MAX_SIZE];
        size_t test1 = getline_(test1_to_func, 10, test_fgets_);
        size_t test1_ref = 4;

        char test2_to_func[MAX_SIZE];
        size_t test2 = getline_(test2_to_func, 5, test_fgets_);
        size_t test2_ref = 4;

        cmp_data_int(test1, test1_ref);
        cmp_data_int(test2, test2_ref);

        printf("\n");
}

void test_strstr_()
{
        printf(ANSI_LIGHT_YELLOW "STRSTR_\n" ANSI_DEFAULT_COLOR);

        const char *st = "abcdefgh";

        int test1 = strstr_(st, "defg") - st + 1;
        int test1_ref = 4;

        int test2 = strstr_(st, "cd") - st + 1;
        int test2_ref = 3;

        cmp_data_int(test1, test1_ref);
        cmp_data_int(test2, test2_ref);

        printf("\n");
}

#endif // TEST_ON
