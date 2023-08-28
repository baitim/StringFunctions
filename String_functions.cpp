#include "String_functions.h"


int puts_(const char *s)
{
        if (s == NULL) {
                errno = EINTR;
                return EOF;
        }

        int i = 0;

        while (s[i]) {
                if (putchar(s[i]) == EOF) {
                        errno = EINTR;
                        return EOF;
                }

                i++;
        }

        if (putchar('\n') == EOF) {
                errno = EINTR;
                return EOF;
        }

        return 1;
}

char *strchr_(const char *s, const int ch)
{
        int i = 0;

        do {
                if (s[i] == ch)
                        return const_cast<char *>(&s[i]);
                i++;
        } while (s[i]);

        return nullptr;
}

size_t strlen_(const char *s)
{
        int i = 0;
        while (s[i] != '\0')
                i++;

        return i;
}

char *strcpy_(char *dest, const char *src)
{
        int i = 0;

        while ((dest[i] = src[i]) != '\0')
                i++;

        return dest;
}

char *strncpy_(char *dest, const char *src, const int n)
{
        int i = 0;

        while ((i < n) && ((dest[i] = src[i]) != '\0'))
                i++;

        while (i < n) {
                dest[i] = '\0';
                i++;
        }

        return dest;
}

char *strcat_(char *dest, const char *src)
{
        int i = 0;
        int j = 0;

        while (dest[i] != '\0')
                i++;

        while ((dest[i] = src[j]) != '\0') {
                i++;
                j++;
        }

        return dest;
}

char *strncat_(char *dest, const char *src, const int n)
{
        int i = 0;
        int j = 0;

        while (dest[i] != '\0')
                i++;

        while ((j < n) && ((dest[i] = src[j]) != '\0')) {
                i++;
                j++;
        }

        dest[i+1] = '\0';

        return dest;
}

char *fgets_(char *s, const int n, FILE *stream)
{
        int i = 0;
        int c = 0;

        while (i < n - 1) {
                if ((c = getc(stream)) == EOF) {
                        if (i == 0) {
                                errno = EIO;
                                return nullptr;
                        } else {
                                return s;
                        }
                }

                if ((s[i] = char(c)) == '\n')
                        return s;

                i++;
        }

        s[i+1] = '\0';

        return s;
}

char *strdup_(const char *src)
{
        char *dest;
        dest = (char *) malloc(strlen_(src));

        if (dest == NULL) {
                errno = EBUSY;
                return nullptr;
        }

        strcpy_(dest, src);
        return dest;
}

size_t getline_(char *s, const int n, FILE *stream)
{
        printf("size of array: %u\n", sizeof(s));
        if (sizeof(s) / sizeof(s[0]) < n)
                s = (char *) realloc(s, n * sizeof(char));


        int i = 0;
        int c = 0;

        while (i < n - 1) {
                if ((c = getc(stream)) == EOF)
                        return -1;

                if ((s[i] = char(c)) == '\n') {
                        i++;
                        break;
                }
                i++;
        }

        s[i+1] = '\0';

        return i;
}

char *strstr_(const char *s, const char *t)
{
        if (strlen_(t) == 0)
                return const_cast<char *>(s);

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

        return nullptr;
}
