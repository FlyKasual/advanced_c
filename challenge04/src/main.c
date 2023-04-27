#include <stdlib.h>
#include <stdio.h>

int sum(int, int*);

int main(void) {
    int l = 0;
    printf("Enter the size of the array: ");
    scanf("%d", &l);
    int arr[l];
    printf("Enter the %d elements of the array: ", l);
    for(int i = 0; i < l; ++i)
        scanf("%d", &arr[i]);
    printf("The sum of the array elements is: %d\n", sum(l, arr));
    return EXIT_SUCCESS;
}

inline int sum(int l, int *arr) {
    int sum = 0;
    for (int i = 0; i < l; ++i)
        sum += arr[i];
    return sum;
}
