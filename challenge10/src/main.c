#include <stdlib.h>
#include <stdio.h>

int main(void) {
    int input = 0;
    int inputWithBitSet = 0;
    unsigned int bit = 0;
    unsigned int mask = ~0;
    printf("Enter any positive number: ");
    while((scanf("%d", &input)) != 1) {
        int tmp = 0;
        while((tmp = getchar()) != '\n' && tmp != EOF);
        printf("This was not a valid number, please try again: ");
    }

    printf("\nEnter the bit to check (0 - %lu): ", sizeof(int) * 8 - 1);
    while((scanf("%u", &bit)) != 1) {
        int tmp = 0;
        while((tmp = getchar()) != '\n' && tmp != EOF);
        printf("This was not a valid number, please try again: ");
    }

    mask = 1 << bit;
    printf("\nThe %u bit is set to %u\n", bit, (input & mask) == 0 ? 0 : 1);

    inputWithBitSet = input | mask;
    if ((inputWithBitSet & mask) == mask)
        printf("\nSuccessfully set the %u bit to 1\n", bit);
    else
        printf("\nFailure setting the %u bit to 1\n", bit);

    printf("\nNumber before setting the %u bit: %d\n", bit, input);
    printf("Number after setting the %u bit: %d\n\n", bit, inputWithBitSet);

    return EXIT_SUCCESS;
}
