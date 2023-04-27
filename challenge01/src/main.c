#include <stdlib.h>
#include <stdio.h>

static double globalsScopeInternalLinkage = 1.0;
float globalScopeExtrnalLinkage = 2.0;

static void internal(void);

int main(void) {
    int localBlockScopeAutoStorage = 0;
    static float localScopePermanentStorage = 14;
    register int registerVariable = 123;
    return EXIT_SUCCESS;
}

static void internal(void) {
    printf("Only accessible in this file");
}
