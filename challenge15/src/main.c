#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

int main(int argc, char** argv) {
    FILE* fp = NULL;
    FILE* tmpFp = NULL;
    int ch = '\0';

    if (argc < 2) {
        perror("Filename not provided");
        return EXIT_FAILURE;
    } else {
        fp = fopen(argv[1], "r");
        if (fp == NULL) {
            perror("Unable to open file");
            return EXIT_FAILURE;
        }
    }
    tmpFp = fopen(".tmp", "w+");
    if (tmpFp == NULL) {
        perror("Unable to create temporary file");
        fclose(fp);
        fp = NULL;
        return EXIT_FAILURE;
    }

    while((ch = fgetc(fp)) != EOF) {
        if (isupper(ch))
            fputc(tolower(ch), tmpFp);
        else
            fputc(toupper(ch), tmpFp);
    }

    fclose(fp);
    fp = NULL;

    fclose(tmpFp);
    tmpFp = NULL;

    remove(argv[1]);
    rename(".tmp", argv[1]);

    return EXIT_SUCCESS;
}
