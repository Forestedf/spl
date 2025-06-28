#pragma once
#include <algorithm>
#include "../poly/fft.hpp"
// c[i] = sum_{j - k = i} a[j] b[k]
template <typename T>
std::vector<T> convolve_diff(std::vector<T> a, std::vector<T> b) {
    if (a.empty() || b.empty()) {
        return std::vector<T>();
    }
    int n = (int)a.size();
    b.resize(n, T());
    std::reverse(a.begin(), a.end());
    std::vector<T> c = convolve(a, b);
    c.resize(n);
    std::reverse(c.begin(), c.end());
    return c;
}
