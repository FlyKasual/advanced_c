#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

int main(void) {
    int* a = malloc(sizeof(char) * 1);
    #ifdef DEBUG
    fprintf(stderr, "Before hello world!\n");
    #endif
    printf("Hello world!\n");
    #ifdef DEBUG
    fprintf(stderr, "After hello world!\n");
    #endif

    free(a);
    free(a);
    // abort();

    return EXIT_SUCCESS;
}
