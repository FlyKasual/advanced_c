#include <stdlib.h>
#include <stdio.h>

#define SUM(X, Y) ((X) + (Y))

int main(void) {
    int x = 0;
    int y = 0;
    printf("Enter x: ");
    scanf("%d", &x);
    printf("Enter y: ");
    scanf("%d", &y);
    printf("%d + %d is %d\n", x, y, SUM(x, y));
    return EXIT_SUCCESS;
}
