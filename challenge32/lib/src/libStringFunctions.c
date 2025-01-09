#include <stdlib.h>
#include "libStringFunctions.h"

size_t numberOfTimesCharacterInString(const char *const restrict str, const char c) {
    size_t n = 0;
    for (size_t i = 0; str[i] != '\0'; ++i) {
        if (str[i] == c) {
            ++n;
        }
    }
    return n;
}

int removeNonAlphaCharacter(char *restrict str) {
    char *dest = str;

    for (; *str != '\0'; ++str) {
        if ('A' <= *dest && *dest <= 'z') {
            *dest = *str;
            ++dest;
        }
    }
    *dest = '\0';

    return EXIT_SUCCESS;
}

size_t lengthOfString(const char *const restrict str) {
    for (size_t i = 0; ; ++i) {
        if (str[i] == '\0') {
            return i;
        }
    }
}

int strConcat(char *left, const char *const right) {
    size_t l1 = lengthOfString(left);
    for (size_t i = 0; right[i] != '\0'; ++i) {
        left[l1 + i] = right[i];
    }

    return EXIT_SUCCESS;
}

int strCopy(const char *const from, char *const to) {
    if (from == to) {
        return EXIT_SUCCESS;
    }
    /**
     * TODO: Check if from and to overlap?
     */
    size_t i = 0;
    for (i = 0; from[i] != '\0'; ++i) {
        to[i] = from[i];
    }
    to[i] = '\0';

    return EXIT_SUCCESS;
}

int substring(const char *const src, const size_t from, size_t n, char *const dest) {
    size_t l = lengthOfString(src);
    /**
     * TODO: Check if src and dest overlap?
     */
    size_t i = 0;
    if (from > l) {
        return EXIT_FAILURE;
    }
    if (from + n > l) {
        n = l - from;
    }
    for (i = from; i < n; ++i) {
        dest[i] = src[i];
    }
    dest[i] = '\0';
    return EXIT_SUCCESS;
}
