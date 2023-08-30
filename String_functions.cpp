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
        ASSERT(src);


        int i = 0;

        while ((dest[i] = src[i]) != '\0')
                i++;

        return dest;
}

char *strncpy_(char *dest, const char *src, const int n)
{
        ASSERT(dest);
        ASSERT(src);

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

        char *dest = (char *) calloc(strlen_(src), sizeof(char));

        if (dest == NULL) {
                errno = EBUSY;
                return nullptr;
        }

        strcpy_(dest, src);
        return dest;
}

ssize_t getline_(char **s, size_t *n, FILE *stream)
{
        const double add_chars = 1.5f;
        int memory_s = 10;
        if (*s == nullptr) {
                *s = (char *) realloc(*s, memory_s * sizeof(char));
                *n = memory_s;
        }

        if (*s == nullptr) {
                errno = EIO;
                return -1;
        }

        int i = 0;
        int c = 0;

        while ((c = getc(stream)) != EOF) {

                (*s)[i] = char(c);

                if ((*s)[i] == '\n') {
                        i++;
                        break;
                }

                i++;

                if (i == *n - 1) {
                        memory_s = (int) (add_chars * memory_s);
                        *s = (char *) realloc(*s, memory_s * sizeof(char));
                        *n = memory_s;

                        if (*s == nullptr) {
                                errno = EIO;
                                return -1;
                        }
                }
        }

        (*s)[i] = '\0';

        return i;
}

char *strstr_(const char *str, const char *substr)
{
        ASSERT(str);
        ASSERT(substr);

        if (strlen_(substr) == 0)
                return const_cast<char *>(str);

        const int length_str = strlen_(str);
        long long *hash_str = (long long *) calloc(length_str + 1, sizeof(long long));

        for (int i = 1; i <= length_str; i++)
                hash_function(&hash_str[i], &hash_str[i-1], str[i-1]);


        const int length_substr = strlen_(substr);
        long long hash_substr = 0;

        for (int i = 1; i <= length_substr; i++)
                hash_function(&hash_substr, &hash_substr, substr[i-1]);


        long long *base = (long long *) calloc(length_str - length_substr + 1, sizeof(long long));
        base[0] = 1;
        for (int i = 1; i < length_substr + 1; i++)
                base[i] = (base[i - 1] * BASE) % MOD;

        for (int i = 0; i < length_str - length_substr + 1; i++) {

                long long hash_str_ = hash_str[length_substr + i] - (hash_str[i] * base[length_substr]) % MOD;
                hash_str_ = (hash_str_ + MOD * MOD) % MOD;

                if ((hash_substr == hash_str_) && (strncmp_(&str[i], substr, strlen_(substr)) == 0))
                        return const_cast<char *>(&str[i]);
        }

        return nullptr;
}

void hash_function(long long *x, long long *y, char ch)
{
        *x = (((*y * BASE) % MOD + (ch - 'a' + 1)) % MOD);
}

int strncmp_(const char *s, const char *t, size_t count)
{
        int i = 0;

        while (s[i] && t[i] && (i < count)) {
                if (s[i] < t[i])
                        return -1;

                if (s[i] > t[i])
                        return 1;

                i++;
        }

        if (!s[i] && !t[i])
                return 0;

        if (!s[i])
                return -1;

        if (!t[i])
                return 1;

        return 0;
}
