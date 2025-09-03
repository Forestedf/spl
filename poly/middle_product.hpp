#pragma once
#include <algorithm>
#include "fft.hpp"

// a.size() <= b.size()
template <typename M>
std::vector<M> middle_product(std::vector<M> a, std::vector<M> b) {
    int n = (int)a.size();
    int m = (int)b.size();
    std::reverse(a.begin(), a.end());
    int l = 1;
    while (l < m) {
        l *= 2;
    }
    a.resize(l, M());
    b.resize(l, M());
    fft(a);
    fft(b);
    for (int i = 0; i < l; ++i) {
        b[i] *= a[i];
    }
    ifft(b);
    return std::vector<M>(b.begin() + (n - 1), b.begin() + m);
}
