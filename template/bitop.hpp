#pragma once

template <typename T, typename U>
bool ith_bit(T n, U i) {
    return (n & ((T)1 << i)) != 0;
}

int popcount(int x) { return __builtin_popcount(x); }
unsigned popcount(unsigned x) { return __builtin_popcount(x); }
long long popcount(long long x) { return __builtin_popcountll(x); }
unsigned long long popcount(unsigned long long x) {
    return __builtin_popcountll(x);
}

// x must not be 0
int clz(int x) { return __builtin_clz(x); }
unsigned clz(unsigned x) { return __builtin_clz(x); }
long long clz(long long x) { return __builtin_clzll(x); }
unsigned long long clz(unsigned long long x) { return __builtin_clzll(x); }

// x must not be 0
int ctz(int x) { return __builtin_ctz(x); }
unsigned ctz(unsigned int x) { return __builtin_ctz(x); }
long long ctz(long long x) { return __builtin_ctzll(x); }
unsigned long long ctz(unsigned long long x) { return __builtin_ctzll(x); }

int floor_log2(int x) { return 31 - clz(x); }
unsigned floor_log2(unsigned x) { return 31 - clz(x); }
long long floor_log2(long long x) { return 63 - clz(x); }
unsigned long long floor_log2(unsigned long long x) { return 63 - clz(x); }

template <typename T>
T mask_n(T x, T n) {
    T mask = ((T)1 << n) - 1;
    return x & mask;
}
