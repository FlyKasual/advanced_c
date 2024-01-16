#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// some random numbers
int array1[10] = { 10, 20, 30, 40, 50, 60, 70, 80, 90, 100 };
int array2[10] = { 38, 27, 87, 63, 59, 223, 132, 1, 19, 7 };


int add(int a, int b) { return a + b; }
int sub(int a, int b) { return a - b; }
int mult(int a, int b) { return a * b; }
int divide(int a, int b) { return a / b; }

/// Array of pointers to functions
// INSERT YOUR FUNCTION POINTER INITIALIZATION HERE = { &add,&sub,&mult,&divide };
typedef int (*Operation)(int, int);
Operation operations[4] = { &add, &sub, &mult, &divide };

// performs the given operation on elements of the arrays
void performOp(int *a, int *b, int **dest, int size, Operation op);

// displays the elements of an array
void display(int *x, int size);

// main method
int main(void) {
    int choice = 0;

    // size of the array
    unsigned int size = 0;

    int *result = NULL;

    // set size to minimum size of the two arrays
    size = sizeof(array1);

    if (sizeof(array2) < size)
        size = sizeof(array2);

    size = size / sizeof(int);

    while(choice != 5) {
        printf("\n\nWhich operation do you want to perform? \n");
        printf("1.Add \n");
        printf("2.Subtract \n");
        printf("3.Multiply \n");
        printf("4.Divide \n");
        printf("5.None ... \n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        if(choice == 5) break;
        if(choice < 1 || choice > 5) continue;

        int j = choice - 1;

        performOp(array1, array2, &result, size, operations[j]);

        printf("\n\nThe Results are ...\n");
        display(result, size);

        if(result != NULL) {
            free(result);
            result = NULL;
        }

        printf("\nresult = %p", (void*)result);
    }

    return EXIT_SUCCESS;
}


// performs the given operation on all elements of the arrays A and B
void performOp(int *a, int *b, int **dest, int size, Operation op) {
    if (dest != NULL) {
        free(*dest);
        *dest = calloc(size, sizeof(int));
        for (int i = 0; i < size; ++i) {
            (*dest)[i] = (*op)(a[i], b[i]);
        }
    }
}


// function for displaying the results stored in array x
void display(int *x, int size) {
    if (x != NULL) {
        printf("\n{ ");
        for (int i = 0; i < size; ++i) {
            if (i == 0) {
                printf("%d", x[i]);
            } else {
                printf(", %d", x[i]);
            }
        }
        printf(" }\n");
    }
}
