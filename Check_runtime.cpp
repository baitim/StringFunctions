#include "Check_runtime.h"

#include <string.h>

void runtime_test()
{
	FILE *fp = fopen("Runtime_test.txt", "r");

        if (fp == NULL) {
                printf(ANSI_LIGHT_RED "Runtime test file read error\n\n" ANSI_DEFAULT_COLOR);
                return;
        }

	char *st = nullptr;
        size_t n = 0 * sizeof(char);
        getline_(&st, &n, fp);

        fclose(fp);

	clock_t start_time1 = clock();

	int answer1 = 0;

	for (int i = 0; i < 1000; i++) {
		answer1 = strstr_(st, "XZZZXZZYYXXZYXXZZXXXXXZZZXYXXZX") - st + 1;
	}

	clock_t end_time1 = clock();

	printf(ANSI_LIGHT_YELLOW "Answer my strstr_ : %d\n" ANSI_DEFAULT_COLOR, answer1);
	printf(ANSI_LIGHT_CYAN "Runtime my strstr_ : %f ms\n" ANSI_DEFAULT_COLOR,
				1000.0 * (end_time1 - start_time1) / CLOCKS_PER_SEC);


	clock_t start_time2 = clock();

	int answer2 = 0;

	for (int i = 0; i < 1000; i++) {
		answer2 = strstr(st, "XZZZXZZYYXXZYXXZZXXXXXZZZXYXXZX") - st + 1;
	}

	clock_t end_time2 = clock();

	printf(ANSI_LIGHT_YELLOW "Answer strstr : %d\n" ANSI_DEFAULT_COLOR, answer2);
	printf(ANSI_LIGHT_CYAN "Runtime strstr : %f ms\n" ANSI_DEFAULT_COLOR,
				1000.0 * (end_time2 - start_time2) / CLOCKS_PER_SEC);

	free(st);
}
