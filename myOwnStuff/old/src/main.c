    #include <stdio.h>
    int main()    {
        int a[3] = {1, 2, 3};
        int *p = a;
        int **r = &p;
        printf("%p %p", *r, a);

        return 0;
    }
