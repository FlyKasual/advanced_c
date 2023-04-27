#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char** argv) {
    if (argc < 3) {
        perror("Two arguments required");
        return EXIT_FAILURE;
    }

    int ch = argv[1][0];
    size_t l = 256;
    char *str = NULL;
    FILE* fp = NULL;

    if ((str = calloc(l, sizeof(char))) == NULL) {
        perror("Unable to allocate memory for string");
        return EXIT_FAILURE;
    }

    if ((fp = fopen(argv[2], "r")) == NULL) {
        perror("Unable to open file");
        free(str);
        str = NULL;
        return EXIT_FAILURE;
    }

    while(getline(&str, &l, fp) != -1) {
        if (strchr(str, ch) != NULL) {
            str[strlen(str) - 1] = '\0';
            puts(str);
        }
    }

    fclose(fp);
    fp = NULL;
    free(str);
    str = NULL;

    return EXIT_SUCCESS;
}
