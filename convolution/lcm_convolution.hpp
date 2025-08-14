#pragma once
#include <cassert>
#include <vector>
// length: max(a.size(), b.size())
// ignore index 0
template <typename T>
std::vector<T> lcm_convolution(std::vector<T> a, std::vector<T> b) {
    if (a.size() <= 1 || b.size() <= 1) {
        return std::vector<T>(std::max(a.size(), b.size()), T(0));
    }
    if (a.size() > b.size()) {
        a.swap(b);
    }
    int n = (int)b.size();
    a.resize(n, T(0));
    std::vector<int> is_prime(n, 1);
    for (int i = 2; i < n; ++i) {
        if (!is_prime[i]) {
            continue;
        }
        for (int j = 1, k = i; k < n; ++j, k += i) {
            a[k] += a[j];
            b[k] += b[j];
            is_prime[k] = 0;
        }
        is_prime[i] = 1;
    }
    for (int i = 1; i < n; ++i) {
        b[i] *= a[i];
    }
    for (int i = 2; i < n; ++i) {
        if (!is_prime[i]) {
            continue;
        }
        for (int j = (n - 1) / i, k = j * i; j >= 1; --j, k -= i) {
            b[k] -= b[j];
        }
    }
    b[0] = T(0);
    return b;
}
