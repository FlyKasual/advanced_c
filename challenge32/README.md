Commands to compile all this from the docroot:
```bash
gcc -Wall -Wextra -Wpedantic -Werror -O3 --std=c17 -fPIC -I challenge32/lib/include challenge32/lib/src/libStringFunctions.c -shared -o challenge32/lib/libStringFunctions.so
gcc -Wall -Wextra -Wpedantic -Werror -O3 --std=c17 -I challenge32/lib/include -I challenge32/include -c challenge32/src/main.c -o challenge32/build/main.o
gcc challenge32/build/main.o -L challenge32/lib -l StringFunctions -o challenge32/build/main
rm challenge32/build/main.o
```
