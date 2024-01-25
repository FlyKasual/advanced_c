#ifndef LIB_STRING_FUNCTIONS_1705673565_H
#define LIB_STRING_FUNCTIONS_1705673565_H

#include <stddef.h>

/**
 * I am fairly certain a lot of these will not be memory safe!
 */
size_t numberOfTimesCharacterInString(const char *const restrict str, const char c);
int removeNonAlphaCharacter(char *restrict str);
size_t lengthOfString(const char *const restrict str);
int strConcat(char * left, const char *const right);
int strCopy(const char *const from, char *const to);
int substring(const char *const src, const size_t from, size_t n, char *const dest);

#endif
