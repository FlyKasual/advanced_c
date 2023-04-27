#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Fac.h"

int main(void) {
    unsigned int n = 0;
    unsigned long long facN = 0;
    clock_t begin = 0;
    clock_t end = 0;
    double time = 0;

    printf("Please enter a number: ");
    scanf("%u", &n);

    begin = clock();

    facN = fac(n);

    end = clock();
    time = (double)(end - begin) / CLOCKS_PER_SEC;

    printf("%u! = %llu\n\nCalculated in %f seconds\n", n, facN, time);

    return EXIT_SUCCESS;
}
