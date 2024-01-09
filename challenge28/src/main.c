#include <stdlib.h>
#include <stdio.h>
#include <memory.h>

int main(void) {
    int x = 3;
    int* p = &x;
    int** pp = &p;

    printf(
        "x = %d\n"
        "p = &x = %p\n"
        "*p = x = %d\n"
        "pp = &p = %p\n"
        "*pp = p = &x = %p\n"
        "**pp = *p = x = %u\n"
        "&pp = %p\n",
        x,
        (void*)p,
        *p,
        (void*)pp,
        (void*)*pp,
        **pp,
        (void*)&pp
    );

    return EXIT_SUCCESS;
}
