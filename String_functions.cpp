#include "String_functions.h"


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
