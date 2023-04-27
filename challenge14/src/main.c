#include <stdlib.h>
#include <stdio.h>

int main(int argc, char** argv) {
    FILE* fp = NULL;
    int ch = '\0';
    int prevCh = ' ';
    int wordCount = 0;
    int characterCount = 0;

    if (argc == 1)
        fp = stdin;
    else
        fp = fopen(argv[1], "r");
    if (fp == NULL) {
        perror("Unable to open file");
        return EXIT_FAILURE;
    }

    while((ch = fgetc(fp)) != EOF) {
        ++characterCount;
        if (
            (ch != ' ' && ch != '\n' && ch != '\t' && ch != '\r')
            && (prevCh == ' ' || prevCh == '\n' || prevCh == '\t' || prevCh == '\r')
        )
            ++wordCount;
        prevCh = ch;
    }

    fclose(fp);
    fp = NULL;

    printf("The provided file contains %d characters and %d words.\n", characterCount, wordCount);

    return EXIT_SUCCESS;
}
