#include <stdlib.h>
#include <stdio.h>

unsigned int sum(unsigned int);
static unsigned int _s(register unsigned int, register unsigned int);

int main(void) {
    unsigned int n = 0;
    printf("Input the last number of the range starting fom 1: ");
    while(scanf("%u", &n) != 1 && n < 1) {
        int _tmp = '\0';
        while((_tmp = getchar()) != '\n' && _tmp != EOF);
        printf("This was not a valid input. Please try again: ");
    }

    printf("The sum of the first %u integers is %u\n", n, sum(n));

    return EXIT_SUCCESS;
}

unsigned int sum(unsigned int n) {
    return _s(0, n);
}

static unsigned _s(register unsigned int a, register unsigned int b) {
    return b == 0 ? a : _s(a + b, b - 1);
}
