#include <stdio.h>

extern int i;

void foo(void) {
    printf("%d\n", i + 1);
}
