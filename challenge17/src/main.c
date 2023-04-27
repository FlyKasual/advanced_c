#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

bool isPrime(const int);

int main(int argc, char** argv) {
    if (argc < 2) {
        perror("Too few arguments provided");
        exit(EXIT_FAILURE);
    }

    FILE* fp = NULL;
    if ((fp = fopen(argv[1], "r")) == NULL){
        perror("Unable to open file");
        exit(EXIT_FAILURE);
    }

    int i = 0;
    while (fscanf(fp, "%d", &i) != -1)
        printf("Found %s number: %d \n", isPrime(i) ? "a prime" : ((i % 2 == 0) ? "an even" : "an odd"), i);

    fclose(fp);
    fp = NULL;

    return EXIT_SUCCESS;
}

bool isPrime(const int n) {
    if (n == 2 || n == 3)
        return true;
    if (n <= 1 || n % 2 == 0 || n % 3 == 0)
        return false;
    for (int i = 5; i * i <= n; i += 6)
        if (n % i == 0 || n % (i + 2) == 0)
            return false;
    return true;
}
