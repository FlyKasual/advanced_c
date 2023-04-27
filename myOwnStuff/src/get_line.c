#include <stdlib.h>
#include <stdio.h>

int __main(void) {
    char* str = NULL;
    size_t len = 4;
    size_t num = 0;

    str = calloc(len, sizeof(char));
    if (str == NULL) {
        perror("Unable to allocate memory");
        return EXIT_FAILURE;
    }

    printf("Type something: ");
    num = getline(&str, &len, stdin);

    printf("%zu bytes were read\n", num);
    printf("len is %zu\n", len);
    printf("You typed: %s\n", str);

    free(str);
    str = NULL;
    return EXIT_SUCCESS;
}
