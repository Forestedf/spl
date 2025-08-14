#pragma once
#include <cassert>
#include <vector>
// length: max(a.size(), b.size())
template <typename T>
std::vector<T> gcd_convolution(std::vector<T> a, std::vector<T> b) {
    if (a.empty() || b.empty()) {
        return std::vector<T>(std::max(a.size(), b.size()), 0);
    }
    if (a.size() > b.size()) {
        a.swap(b);
    }
    int m = (int)a.size();
    int n = (int)b.size();
    std::vector<T> c(n, T());
    for (int i = 0; i < m; ++i) {
        c[i] += a[i] * b[0];
    }
    for (int i = 1; i < n; ++i) {
        c[i] += a[0] * b[i];
    }
    std::vector<int> is_prime(n, 1);
    for (int i = 2; i < n; ++i) {
        if (!is_prime[i]) {
            continue;
        }
        // k * i < n
        // k < n / i
        for (int j = (n - 1) / i, k = j * i; j >= 1; --j, k -= i) {
            is_prime[k] = 0;
            b[j] += b[k];
        }
        for (int j = (m - 1) / i, k = j * i; j >= 1; --j, k -= i) {
            a[j] += a[k];
        }
        is_prime[i] = 1;
    }
    for (int i = 1; i < m; ++i) {
        b[i] *= a[i];
    }
    for (int i = m; i < n; ++i) {
        b[i] = T();
    }
    for (int i = 2; i < m; ++i) {
        if (!is_prime[i]) {
            continue;
        }
        for (int j = 1, k = i; k < m; ++j, k += i) {
            b[j] -= b[k];
        }
    }
    for (int i = 1; i < m; ++i) {
        c[i] += b[i];
    }
    return c;
}
