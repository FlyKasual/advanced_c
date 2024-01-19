#include <stdio.h>
#include <stdlib.h>
#include <setjmp.h>

jmp_buf buf;

void myFunc(void);

int ___main(void) {
    printf("At the start of main\n");
    if (setjmp(buf)) {
        printf("Second printf in main\n");
    } else {
        printf("Right before calling myFunc\n");
        myFunc();
    }
    return EXIT_SUCCESS;
}

void myFunc(void) {
    printf("In myFunc\n");
    longjmp(buf, 1);
}
