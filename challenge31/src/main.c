#include <stdlib.h>
#include <stdio.h>
#include "libStringFunctions.h"

#define SIZE 1024

int main(void) {
    char str1[SIZE] = "The quick brown fox jumps over the lazy dog.";
    char str2[SIZE] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890!\"§$&/()=?abcdefghijklmnopqrstuvwxyz";
    char str[SIZE];
    *str = '\0';
    size_t l = lengthOfString(str1);
    printf("str1 is %lu characters long.\n", l);
    printf("The character 'e' appears %lu times in \"Johannes Nielsen\"\n", numberOfTimesCharacterInString("Johannes Nielsen", 'e'));
    removeNonAlphaCharacter(str2);
    printf("By removing all non alpha characters, str2 becomes: %s\n", str2);
    strConcat(str1, str2);
    printf("Concatenating the two strings yields: %s\n", str1);
    substring(str1, 0, l, str);
    printf("str is now: %s\n", str);
    strCopy(str, str1);
    printf("str1 now is: %s\n", str1);
    *str = '\0';

    return EXIT_SUCCESS;
}
