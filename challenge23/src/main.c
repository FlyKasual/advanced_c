#include <stdlib.h>
#include <stdio.h>

int main(void) {

    printf(
        "%s – %s: Line %d in file %s, using C%d\n",
        __DATE__,
        __TIME__,
        __LINE__,
        __FILE__,
        __STDC__
    );

    return EXIT_SUCCESS;
}
