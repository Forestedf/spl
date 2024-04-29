#pragma once
#include <cassert>
#include <utility>
#include <vector>
#include "../number_theory/factorial.hpp"
// O(n * (# of nonzero))
template <typename T>
std::vector<T> fps_log_sparse(const std::vector<T> &f) {
    assert(!f.empty() && f[0] == T(1));
    int n = (int)f.size();
    std::vector<std::pair<int, T>> nonzero;
    for (int i = 1; i < n; ++i) {
        if (f[i] != T()) {
            nonzero.emplace_back(i, f[i]);
        }
    }
    std::vector<T> g = f;
    g[0] = T(0);
    for (int i = 1; i < n; ++i) {
        T sum;
        for (auto [j, val] : nonzero) {
            if (j > i) {
                break;
            }
            sum += T(i - j) * val * g[i - j];
        }
        g[i] -= inv<T>(i) * sum;
    }
    return g;
}
