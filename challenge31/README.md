Commands to compile all this from the docroot:
```bash
gcc -Wall -Wextra -Wpedantic -Werror -O3 --std=c17 -I challenge31/lib/include -c challenge31/lib/src/libStringFunctions.c -o challenge31/lib/libStringFunctions.o
ar rcs challenge31/lib/libStringFunctions.a challenge31/lib/libStringFunctions.o
rm challenge31/lib/libStringFunctions.o
gcc -Wall -Wextra -Wpedantic -Werror -O3 --std=c17 -I challenge31/lib/include -I challenge31/include -c challenge31/src/main.c -o challenge31/build/main.o
gcc challenge31/build/main.o -L challenge31/lib -l StringFunctions -o challenge31/build/main
rm challenge31/build/main.o
```
