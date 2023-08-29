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
        const int add_chars = 20;
        if (*s == nullptr) {
                *s = (char *) realloc(*s, add_chars * sizeof(char));
                *n = add_chars;
        }

        int i = 0;
        int c = 0;

        while (((c = getc(stream)) != EOF)) {

                if (((*s)[i] = char(c)) == '\n') {
                        i++;
                        break;
                }

                if (i == *n-1) {;
                        *s = (char *) realloc(*s, (*n + add_chars) * sizeof(char));
                        *n += add_chars;
                }
                i++;
        }

        (*s)[i] = '\0';

        return i;
}

char *strstr_(const char *s, const char *t)
{
        ASSERT(s);
        ASSERT(t);

        if (strlen_(t) == 0)
                return const_cast<char *>(s);

        const int Ns = strlen_(s);
        const int Nt = strlen_(t);

        long long hash_value[MAX_SIZE];
        hash_value[0] = 0;
        long long p_pow = 1;
        for (int i = 1; i <= Ns; i++) {
                hash_value[i] = (((hash_value[i - 1] * base_) % m + (s[i] - 'a' + 1)) % m);
                p_pow = (p_pow * base_) % m;
        }

        long long hash_t = 0;
        p_pow = 1;
        for (int i = 0; i < Nt; i++) {
                hash_t = (((hash_t * base_) % m + (t[i] - 'a' + 1)) % m);
                p_pow = (p_pow * base_) % m;
        }

        long long base[MAX_SIZE];
        base[0] = 1;
        for (int i = 1; i < Ns + 1; i++)
                base[i] = (base[i - 1] * base_) % m;

        for (int i = 0; i < Ns - Nt + 1; i++) {

                long long hash_str = (hash_value[Nt + i] - (hash_value[i]*base[Nt]) % m + m * m) % m;

                if (hash_t == hash_str)
                        return const_cast<char *>(&s[i]);
        }

        return nullptr;
}

bool compare_(const char *s, const char *t)
{
        int i = 0;

        while (s[i] && t[i]) {
                if (s[i] != t[i])
                        return false;
                i++;
        }


        if (t[i] == '\0')
                return true;
        return false;
}
