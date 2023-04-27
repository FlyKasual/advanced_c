#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>

int _sum(unsigned int, ...);

int main(void) {
    printf("%d\n", _sum(2, 10, 20));
    printf("%d\n", _sum(3, 10, 20, 30));
    printf("%d\n", _sum(4, 10, 20, 30, 40));
    printf("%d\n", _sum(4, 10, 20, 30, -40));
    return EXIT_SUCCESS;
}

int _sum(unsigned int n, ...) {
    va_list parg;
    va_start(parg, n);
    int runningTotal = 0;
    for (unsigned int i = 0; i < n; ++i)
        runningTotal += va_arg(parg, int);
    va_end(parg);

    return runningTotal;
}
