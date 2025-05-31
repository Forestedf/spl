#pragma once

unsigned long long binary_gcd(unsigned long long x, unsigned long long y) {
    if (x == 0) {
        return y;
    }
    if (y == 0) {
        return x;
    }
    int a = __builtin_ctz(x);
    int b = __builtin_ctz(y);
    x >>= a;
    y >>= b;
    while (x != y) {
        int m = __builtin_ctz(x - y);
        if (x > y) {
            x = (x - y) >> m;
        } else {
            y = (y - x) >> m;
        }
    }
    return x << (a < b ? a : b);
}
