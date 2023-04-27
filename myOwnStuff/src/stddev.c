#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>
#include <math.h>

double sample_stddev(unsigned int, ...);

int _____main(void) {
    printf("%f\n", sample_stddev(4U, 25.0, 27.3, 26.9, 25.7));
    return EXIT_SUCCESS;
}
double sample_stddev(unsigned int count, ...) {
    va_list parg;
    va_start(parg, count);

    va_list pargCopy;
    va_copy(pargCopy, parg);

    double runningTotal = 0.0;
    double mean = 0.0;
    double totalQuadraticDeviation = 0.0;
    double stddev = 0.0;

    for (unsigned int i = 0; i < count; ++i)
        runningTotal += va_arg(pargCopy, double);
    va_end(pargCopy);
    mean = runningTotal / count;

    for (unsigned int i = 0; i < count; ++i) {
        double val = va_arg(parg, double);
        totalQuadraticDeviation += (val - mean) * (val - mean);
    }
    va_end(parg);

    stddev = sqrt(totalQuadraticDeviation / count);

    return stddev;
}
