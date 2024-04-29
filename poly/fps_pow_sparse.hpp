#pragma once
#include <algorithm>
#include <cassert>
#include <utility>
#include <vector>
#include "../number_theory/factorial.hpp"
// O(n * (# of nonzero))
template <typename T>
std::vector<T> fps_pow_sparse_constant_1(const std::vector<T> &f, T m) {
    assert(!f.empty() && f[0] == T(1));
    int n = (int)f.size();
    std::vector<std::pair<int, T>> nonzero;
    for (int i = 1; i < n; ++i) {
        if (f[i] != T()) {
            nonzero.emplace_back(i, f[i]);
        }
    }
    std::vector<T> g(f.size(), T(0));
    g[0] = T(1);
    for (int i = 1; i < n; ++i) {
        for (auto [j, val] : nonzero) {
            if (j > i) {
                break;
            }
            g[i] += ((m + T(1)) * T(j) - T(i)) * val * g[i - j];
        }
        g[i] *= inv<T>(i);
    }
    return g;
}
template <typename T>
std::vector<T> fps_pow_sparse(std::vector<T> f, long long m) {
    assert(m >= 0);
    if (m == 0) {
        std::vector<T> g(f.size());
        if (!g.empty()) {
            g[0] = T(1);
        }
        return g;
    }
    int n = (int)f.size();
    int ord = -1;
    for (int i = 0; i < n; ++i) {
        if (f[i] != T(0)) {
            ord = i;
            break;
        }
    }
    if (ord == -1 || (m > 0 && (long long)ord > (long long)n / m)) {
        return std::vector<T>(f.size(), T(0));
    }
    std::rotate(f.begin(), f.begin() + ord, f.end());
    T first = f[0];
    T inv_first = T(1) / f[0];
    for (int i = 0; i < n; ++i) {
        f[i] *= inv_first;
    }
    std::vector<T> g = fps_pow_sparse_constant_1(f, T(m));
    int ret_ord = (int)(ord * m);
    std::rotate(g.begin(), g.begin() + (n - ret_ord), g.end());
    std::fill(g.begin(), g.begin() + ret_ord, T(0));
    T pw = first.pow(m);
    for (int i = ret_ord; i < n; ++i) {
        g[i] *= pw;
    }
    return g;
}
