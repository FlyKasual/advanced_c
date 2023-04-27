#include <stdlib.h>
#include <stdio.h>

struct myArray {
    size_t length;
    int array[];
};

int main(void) {
    struct myArray* arr = NULL;
    size_t len = 0;
    printf("How large should the array be? ");
    scanf("%zd", &len);
    arr = malloc(sizeof(struct myArray) + len * sizeof(int));
    arr->length = len;
    for (size_t i = 0; i < arr->length; ++i)
        arr->array[i] = i % 2 == 0 ? i / 2 : 3 * i + 1;

    for (size_t i = 0; i < arr->length; ++i)
        printf("%d\n", arr->array[i]);

    free(arr);
    return EXIT_SUCCESS;
}
