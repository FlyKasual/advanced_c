#ifndef LIB_STRING_FUNCTIONS_1705673565_H
#define LIB_STRING_FUNCTIONS_1705673565_H

#include <stddef.h>

/**
 * I am fairly certain a lot of these will not be memory safe!
 */
size_t numberOfTimesCharacterInString(const char *const, const char);
int removeNonAlphaCharacter(char * /* make the pointer const, too? */);
size_t lengthOfString(const char *const);
int strConcat(char *, const char *const);
int strCopy(const char *const, char * /* make the pointer const, too? */);
int substring(const char *const, size_t, size_t, char * /* make the pointer const, too? */);

#endif
