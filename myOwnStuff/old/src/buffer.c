#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

int _main(void) {
    char buff[1024];

    memset(buff, '\0', sizeof(buff));

    fprintf(stdout, "Going to set full buffering on (whatever that means)\n");
    setvbuf(stdout, buff, _IOFBF, 1024);

    fprintf(stdout, "This is some program\n");
    fprintf(stdout, "This output woll go into buff\n");
    fflush(stdout);

    fprintf(stdout, "This will appear when the programm\n");
    fprintf(stdout, "comes back after sleeping 5 seconds.\n");

    sleep(5);

    return EXIT_SUCCESS;
}
