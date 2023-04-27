#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

enum Color {
    red = 1,
    green = 2,
    blue = 4,
    black = red & green & blue,
    yellow = red | green,
    magenta = red | blue,
    cyan = green | blue,
    white = red | green | blue
};

enum BorderStyle {
    solid = 0,
    dotted = 1,
    dashed = 2,
};

struct OnscreenBox {
    bool opaque: 1;
    enum Color fillColor: 3;
    unsigned int : 4;
    bool showBorder: 1;
    enum Color borderColor: 3;
    enum BorderStyle borderStyle: 2;
    unsigned int : 2;
};

int main(void) {
    struct OnscreenBox osb= {
        .opaque = true,
        .fillColor = black,
        .showBorder = false,
        .borderColor = black,
        .borderStyle = solid
    };

    printf("The size of an OnscreenBox is %lu bytes\n\n", sizeof(osb));

    printf("\nBefore modification:\n\tosb.opaque = %u\n\tosb.fillColor = %u\n\tosb.showBorder = %u\n\tosb.borderColor = %u\n\tosb.borderStyle = %u\n", osb.opaque, osb.fillColor, osb.showBorder, osb.borderColor, osb.borderStyle);

    osb.fillColor = cyan;
    osb.showBorder = 1,
    osb.borderColor = green;
    osb.borderStyle = dashed;
    printf("\nAfter modification:\n\tosb.opaque = %u\n\tosb.fillColor = %u\n\tosb.showBorder = %u\n\tosb.borderColor = %u\n\tosb.borderStyle = %u\n", osb.opaque, osb.fillColor, osb.showBorder, osb.borderColor, osb.borderStyle);

    return EXIT_SUCCESS;
}
