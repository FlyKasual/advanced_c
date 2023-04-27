#include <stdlib.h>
#include <stdio.h>
#include <math.h>

long long convertBinaryToDecimal(long long);
long long convertDecimalToBinary(long long);
static long long convertBase(long long, int, int);

int main(void) {
    long long myNum = 1001001;
    printf("%lld\n", convertBinaryToDecimal(myNum));
    printf("%lld\n", convertDecimalToBinary(convertBinaryToDecimal(myNum)));
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

long long convertBinaryToDecimal(long long x) {
    return convertBase(x, 2, 10);
}

long long convertDecimalToBinary(long long x) {
    return convertBase(x, 10, 2);
}
