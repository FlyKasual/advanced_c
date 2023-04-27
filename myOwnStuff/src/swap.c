#include <stdlib.h>
#include <stdio.h>

void swapptr(register const void**, register const void**);

int ___________main(void) {
    int i = 4;
    int j = 2;
    int* iptr = &i;
    int* jptr = &j;

    swapptr((void*)&iptr, (void*)&jptr);

    printf("*iptr = %d, *jptr = %d\n", *iptr, *jptr);

    return EXIT_SUCCESS;
}

// void swapptr(register const void** p1, register const void** p2) {
//     *(int*)p1 ^= *(int*)p2;
//     *(int*)p2 ^= *(int*)p1;
//     *(int*)p1 ^= *(int*)p2;
// }

void swapptr(register const void** p1, register const void** p2) {
    register const void* tmp = *p1;
    *p1 = *p2;
    *p2 = tmp;
}
