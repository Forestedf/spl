#pragma once
#include "taylor_shift.hpp"
template <typename M>
std::vector<M> stirling_1_signed(int n) {
    assert(0 <= n);
    if (n == 0) {
        return std::vector<M>(1, M(1));
    }
    std::vector<M> f{M(0), M(1)};
    int lg = 31 - __builtin_clz(n);
    for (int i = lg - 1; i >= 0; --i) {
        f = convolve(f, taylor_shift(f, -M(n >> (i + 1))));
        if (n & (1 << i)) {
            M k((n >> i) - 1);
            f.push_back(M());
            for (int j = (int)f.size() - 1; j > 0; --j) {
                f[j] = f[j - 1] - f[j] * k;
            }
            f[0] = -k * f[0];
        }
    }
    return f;
}
template <typename M>
std::vector<M> stirling_1_unsigned(int n) {
    assert(0 <= n);
    std::vector<M> f = stirling_1_signed<M>(n);
    for (int i = n - 1; i >= 0; i -= 2) {
        f[i] = -f[i];
    }
    return f;
}
