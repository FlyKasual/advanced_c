#include <stdlib.h>
#include <stdio.h>

int sum(int);

int main(void) {
    printf("%d\n", sum(25));
    printf("%d\n", sum(15));
    printf("%d\n", sum(30));
    return EXIT_SUCCESS;
}

int sum(int x) {
    static int runningTotal = 0;
    runningTotal += x;

    return runningTotal;
}
