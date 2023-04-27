#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#define RED 1
#define GREEN 2
#define BLUE 4
#define BLACK RED & GREEN & BLUE
#define YELLOW RED | GREEN
#define MAGENTA RED | BLUE
#define CYAN GREEN | BLUE
#define WHITE RED | GREEN | BLUE

#define SOLID 0
#define DOTTED 1
#define DASHED 2

struct OnscreenBox {
    bool opaque: 1;
    unsigned short fillColor: 3;
    unsigned short : 4;
    bool showBorder: 1;
    unsigned short borderColor: 3;
    unsigned short borderStyle: 2;
    unsigned short : 2;
};

int main(void) {
    struct OnscreenBox osb= {
        .opaque = true,
        .fillColor = BLACK,
        .showBorder = false,
        .borderColor = BLACK,
        .borderStyle = SOLID
    };

    printf("The size of an OnscreenBox is %lu bytes\n\n", sizeof(osb));

    printf("\nBefore modification:\n\tosb.opaque = %u\n\tosb.fillColor = %u\n\tosb.showBorder = %u\n\tosb.borderColor = %u\n\tosb.borderStyle = %u\n", osb.opaque, osb.fillColor, osb.showBorder, osb.borderColor, osb.borderStyle);

    osb.fillColor = CYAN;
    osb.showBorder = 1,
    osb.borderColor = GREEN;
    osb.borderStyle = DASHED;
    printf("\nAfter modification:\n\tosb.opaque = %u\n\tosb.fillColor = %u\n\tosb.showBorder = %u\n\tosb.borderColor = %u\n\tosb.borderStyle = %u\n", osb.opaque, osb.fillColor, osb.showBorder, osb.borderColor, osb.borderStyle);

    return EXIT_SUCCESS;
}
