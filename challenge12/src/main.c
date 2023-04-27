#include <stdlib.h>
#include <stdio.h>

int main(void) {
    int length = 0;
    printf("How tall should the triangle be? ");
    scanf("%d", &length);
    char* str = (char*)calloc(length + 1, sizeof(char));
    if (str == NULL)
        return EXIT_FAILURE;
    int i = length / 2;
    int j = 0;

    // for (int i = 4; i > -1 ; --i) {
    //     for (int j = 0; j < length; ++j) {
    //         if (j == i || j == length - i - 1 || i == 0) {
    //             str[j] = '*';
    //         } else {
    //             str[j] = ' ';
    //         }
    //     }
    //     printf("%s\n", str);
    // }

outer_loop_start:
    if (i <= -1)
        goto outer_loop_end;
    j = 0;
inner_loop_start:
    if (j >= length)
        goto inner_loop_end;
    if (j == i || j == length - i - 1 || i == 0) {
        str[j] = '*';
    } else {
        str[j] = ' ';
    }
    ++j;
    goto inner_loop_start;
inner_loop_end:
    printf("%s\n", str);
    --i;
    goto outer_loop_start;
outer_loop_end:
    free(str);
    str = NULL;

    return EXIT_SUCCESS;
}
