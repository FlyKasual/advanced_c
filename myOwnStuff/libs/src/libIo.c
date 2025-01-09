#include <stdio.h>
#include <stdlib.h>
#include <libIo.h>

int getUserInput(char **restrict str, size_t *restrict len) {
    if (getline(str, len, stdin) == -1) {
        perror("\nUnable to allocate memory");
        free(*str);
        *str = NULL;
        return EXIT_FAILURE;
    }

    /**
     * Trim trailing newline characters
     */
    if (strchr(str, '\n') != NULL) {
        (*str)[strlen(str) - 1] = '\0';
        --(*len);
    }

    return EXIT_SUCCESS;
}
