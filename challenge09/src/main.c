#include <stdlib.h>
#include <stdio.h>
#include <math.h>

static long long convertDecimalToBinary(long long);
static long long convertBase(long long, int, int);

int main(void) {
    int x;
    int y;
    printf("Enter x: ");
    scanf("%d", &x);
    printf("Enter y: ");
    scanf("%d", &y);
    printf("x = %d (%lld)\ty=%d (%lld)\n", x, convertDecimalToBinary(x), y, convertDecimalToBinary(y));
    printf("~x = %d (%lld)\t~y=%d (%lld)\n", ~x, convertDecimalToBinary(~x), ~y, convertDecimalToBinary(~y));
    printf("x & y = %d (%lld)\t\n", x & y, convertDecimalToBinary(x & y));
    printf("x | y = %d (%lld)\t\n", x | y, convertDecimalToBinary(x | y));
    printf("x ^ y = %d (%lld)\t\n", x ^ y, convertDecimalToBinary(x ^ y));
    printf("x >> 2 = %d (%lld)\t\n", x >> 2, convertDecimalToBinary(x >> 2));
    printf("y << 2 = %d (%lld)\t\n", y << 2, convertDecimalToBinary(y << 2));

    return EXIT_SUCCESS;
}

static long long convertBase(long long x, int from, int to) {
    int result = 0;
    int remainder = 0;
    int i = 0;

    while (x != 0) {
        remainder = x % to;
        x /= to;
        result += remainder * powl(from, i++);
    }

    return result;
}

static long long convertDecimalToBinary(long long x) {
    return convertBase(x, 10, 2);
}
