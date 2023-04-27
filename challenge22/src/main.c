#include <stdlib.h>
#include <stdio.h>

union student {
    char letterGrade;
    int roundedGrade;
    float exactGrade;
};

void printStudent(const union student* const s);

int main(void) {
    union student variable1 = { .roundedGrade = 45 };
    union student variable2 = { 'C' };

    printStudent(&variable1);
    printStudent(&variable2);

    variable2.roundedGrade = 75;
    printStudent(&variable2);

    variable2.exactGrade = 74.33;
    printStudent(&variable2);

    return EXIT_SUCCESS;
}

void printStudent(const union student* const s) {
    printf("letter grade: %c\nrounded grade: %d\nexact grade: %f\n\n", s->letterGrade, s->roundedGrade, s->exactGrade);
}
