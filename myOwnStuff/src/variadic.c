#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>

double average(const double v1,...);

int ________main(void) {
    double n1 = 4;
    double n2 = 5;
    double n3 = 6;
    int i = 7;

    printf("%lf\n", average(n1, n2, n3, (double)i));
    return EXIT_SUCCESS;
}

double average(const double v1, ...) {
    va_list parg;
    double result = v1;
    double value = 0.0;
    int n = 1;

    va_start(parg, v1);

    while((value = va_arg(parg, double)) != 0.0) {
        result += value;
        ++n;
    }

    va_end(parg);

    return result / (double)n;
}
