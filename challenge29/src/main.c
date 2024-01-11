#include <stdlib.h>
#include <stdio.h>
#include <memory.h>

void allocateMemory(int **);

int main(void) {
    int *ptr = NULL;
    allocateMemory(&ptr);
    *ptr = 42;
    printf("*ptr = %d\n", *ptr);
    free(ptr);
    ptr = NULL;
    return EXIT_SUCCESS;
}

void allocateMemory(int **p) {
    *p = (int *)malloc(sizeof(int));
}
