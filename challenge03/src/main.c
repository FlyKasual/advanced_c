#include <stdlib.h>
#include <stdio.h>

extern void foo(void);
int i = 0;

int main(void) {
    for (i = 0; i < 5; ++i)
        foo();
    return EXIT_SUCCESS;
}
