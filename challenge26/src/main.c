#include <stdlib.h>
#include <stdio.h>

#define IS_UPPER(C) ('A' <= (C) && (C) <= 'Z')
#define IS_LOWER(C) ('a' <= (C) && (C) <= 'z')

int main(void) {
    char c = '\0';
    printf("Enter any character: ");
    c = getchar();
    if (IS_UPPER(c)) {
        printf("%c is uppercase", c);
    } else if (IS_LOWER(c)) {
        printf("%c is lowercase", c);
    } else {
        printf("%c is not in the alphabet", c);
    }
    printf("\n");
    return EXIT_SUCCESS;
}
