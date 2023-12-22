#include <stdlib.h>
#include <stdio.h>

#define SQUARE(X) ((X) * (X))
#define CUBE(X) ((X) * SQUARE(X))

int main(void) {
    int x = 0;
    printf("Enter x: ");
    scanf("%d", &x);
    printf("%d^2 is %d and %d^3 is %d\n", x, SQUARE(x), x, CUBE(x));
    return EXIT_SUCCESS;
}
