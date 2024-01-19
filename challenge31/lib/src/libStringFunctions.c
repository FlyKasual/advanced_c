#include <stdlib.h>
#include "libStringFunctions.h"

size_t numberOfTimesCharacterInString(const char *const str, const char c) {
    size_t n = 0;
    size_t len = lengthOfString(str);
    for (size_t i = 0; i < len; ++i) {
        if (str[i] == c)
            ++n;
    }
    return n;
}

int removeNonAlphaCharacter(char *str /* make the pointer const, too? */) {
    char *src = str;
    char *dest = str;

    for (; *src != '\0'; ++src) {
        *dest = *src;
        if ('A' <= *dest && *dest <= 'z')
            ++dest;
    }
    *dest = '\0';

    return EXIT_SUCCESS;
}

size_t lengthOfString(const char *const str) {
    for (size_t i = 0; ; ++i) {
        if (str[i] == '\0')
            return i;
    }
}

int strConcat(char *left, const char *const right) {
    size_t l1 = lengthOfString(left);
    size_t l2 = lengthOfString(right);
    for (size_t i = 0; i < l2; ++i) {
        left[l1 + i] = right[i];
    }

    return EXIT_SUCCESS;
}

int strCopy(const char *const from, char * to /* make the pointer const, too? */) {
    size_t i = 0;
    size_t l = lengthOfString(from);
    for (i = 0; i < l; ++i) {
        to[i] = from[i];
    }
    to[i] = '\0';

    return EXIT_SUCCESS;
}

int substring(const char *const src, size_t from, size_t n, char *dest/* make the pointer const, too? */) {
    size_t l = lengthOfString(src);
    size_t i = 0;
    if (from > l)
        return EXIT_FAILURE;
    if (from + n > l)
        n = l - from;
    for (i = from; i < n; ++i)
        dest[i] = src[i];
    dest[i] = '\0';
    return EXIT_SUCCESS;
}
