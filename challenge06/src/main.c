#include <stdlib.h>
#include <stdio.h>
#include <complex.h>
#include <math.h>

int main(void) {
    const double PI = cacos(-1);
    double complex z = I * I;
    double complex z1 = 1 + 2 * I;
    printf("z = %.2f%+.2fi\n", creal(z), cimag(z));

    z = cpow(I, 2);
    printf("z = %.2f%+.2fi\n", creal(z), cimag(z));

    z = cexp(PI * I);
    printf("z = %.2f%+.2fi\n", creal(z), cimag(z));

    z = 1 - 2 * I;
    printf("(1 + 2i)(1 - 2i) = %.2f%+.2fi\n", creal(z * z1), cimag(z * z1));
    return EXIT_SUCCESS;
}
