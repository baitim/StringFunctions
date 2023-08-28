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
        ASSERT(s);
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
        ASSERT(dest);

        int i = 0;

        while ((dest[i] = src[i]) != '\0')
                i++;

        return dest;
}

char *strncpy_(char *dest, const char *src, const int n)
{
        ASSERT(dest);

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
        ASSERT(dest);

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
        ASSERT(dest);

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
        ASSERT(s);

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
        ASSERT(src);

        char *dest;
        dest = (char *) calloc(strlen_(src), sizeof(char));

        if (dest == NULL) {
                errno = EBUSY;
                return nullptr;
        }

        strcpy_(dest, src);
        return dest;
}

size_t getline_(char **s, size_t *n, FILE *stream)
{
        if (*s == nullptr) {
                *s = (char *) realloc(*s, 10 * sizeof(char));
                *n = 10;
        }

        int i = 0;
        int c = 0;

        while (((c = getc(stream)) != EOF)) {

                if (((*s)[i] = char(c)) == '\n') {
                        i++;
                        break;
                }

                if (i == *n-1) {;
                        *s = (char *) realloc(*s, (*n + 10) * sizeof(char));
                        *n += 10;
                }
                i++;
        }

        (*s)[i] = '\0';

        return i;
}

char *strstr_(const char *s, const char *t)
{
        ASSERT(s);

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
