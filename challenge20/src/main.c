#include <stdlib.h>
#include <stdio.h>

unsigned int gcd(register unsigned int, register unsigned int);

int main(void) {
    unsigned int x = 0;
    unsigned int y = 0;

    printf("Enter x: ");
    while(scanf("%u", &x) != 1) {
        int _c = '\0';
        while((_c = getchar()) != '\n' && _c != EOF);
        printf("This was not a valid input. Please try again: ");
    }

    printf("Enter y: ");
    while(scanf("%u", &y) != 1) {
        int _c = '\0';
        while((_c = getchar()) != '\n' && _c != EOF);
        printf("This was not a valid input. Please try again: ");
    }

    printf("gcd(%u, %u) = %u\n", x, y, gcd(x , y));

    return EXIT_SUCCESS;
}

unsigned int gcd(register unsigned int x, register unsigned int y) {
    return y == 0 ? x : gcd(y, x % y);
}
