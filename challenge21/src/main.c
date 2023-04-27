#include <stdlib.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * @brief Store `src` reversed in `dest`
 * @param src Pointer to the string to be reversed
 * @param dest Pointer to where to store the reversed string
 */
inline static void reverseString(const char* const restrict src, char* const restrict dest);

/**
 * @brief Recursive helper function to reverse a string.
 * @param src Pointer to the beginning of the string to be reversed
 * @param end Pointer to the character which needs to be copied next
 * @param dest Pointer to where the next character needs to be copied
 */
static void _r(const char* const src, const char* end, char* restrict dest);

int main(void) {
    size_t len = 0;
    char* str = NULL;
    char* reverse = NULL;

    printf("Enter the string: ");
    /**
     * Exit if memory for the input string can not be allocated.
     */
    if (getline(&str, &len, stdin) == -1) {
        perror("\nUnable to allocate memory");
        free(str);
        str = NULL;
        return EXIT_FAILURE;
    }

    /**
     * Trim trailing newline characters
     */
    if (strchr(str, '\n') != NULL)
        str[strlen(str) - 1] = '\0';

    /**
     * Exit if memory allocation for the reversed string fails.
     */
    if ((reverse = calloc(len, sizeof(char))) == NULL) {
        perror("\nUnable to allocate memory");
        /**
         * Clean up all pointers which have allocated memory so far
         */
        free(str);
        str = NULL;

        return EXIT_FAILURE;
    }

    /**
     * Print all the strings
     */
    printf("The original string is %s\n", str);
    reverseString(str, reverse);
    printf("The reversed string is: %s\n", reverse);

    /**
     * Cleanup
     */
    free(str);
    str = NULL;
    free(reverse);
    reverse = NULL;

    return EXIT_SUCCESS;
}

inline static void reverseString(const char* const restrict src, char* const restrict dest) {
    _r(src, src + strlen(src) - 1, dest);
}

inline static void _r(const char* const src, const char* end, char* restrict dest) {
    *dest = *end;
    if (end != src)
        _r(src, --end, ++dest);
}
