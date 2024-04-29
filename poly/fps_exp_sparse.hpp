#pragma once
#include <cassert>
#include <utility>
#include <vector>
#include "../number_theory/factorial.hpp"
// O(n * (# of nonzero))
template <typename T>
std::vector<T> fps_exp_sparse(const std::vector<T> &f) {
    if (f.empty()) {
        return std::vector<T>(0);
    }
    assert(!f.empty() && f[0] == T(0));
    int n = (int)f.size();
    std::vector<std::pair<int, T>> nonzero;
    for (int i = 1; i < n; ++i) {
        if (f[i] != T()) {
            nonzero.emplace_back(i, f[i]);
        }
    }
    std::vector<T> g(n, T(0));
    g[0] = T(1);
    for (int i = 1; i < n; ++i) {
        for (auto [j, val] : nonzero) {
            if (j > i) {
                break;
            }
            g[i] += T(j) * val * g[i - j];
        }
        g[i] *= inv<T>(i);
    }
    return g;
}
