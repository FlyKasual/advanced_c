#include "libfac.h"

static unsigned long long _fn(register unsigned long long a, register unsigned int b) {
    return b < 2 ? a : _fn(a * b, b - 1);
}

unsigned long long fac(unsigned int n) {
    return _fn(1, n);
}
