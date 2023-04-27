#include <stdlib.h>
#include <stdio.h>
#include <setjmp.h>

jmp_buf jbuf;

void error_recovery(void);

int main(void) {
    while(1) {
        if (setjmp(jbuf)) {
            printf("In main\n");
            break;
        } else {
            error_recovery();
        }
    }
    return EXIT_SUCCESS;
}

void error_recovery(void) {
    printf("There was an error!\n");
    longjmp(jbuf, 42);
}
