#pragma once
#include <cassert>
#include <utility>
#include <vector>
// O(n * (# of nonzero))
template <typename T>
std::vector<T> fps_inv_sparse(const std::vector<T> &f) {
    assert(!f.empty() && f[0] != T(0));
    int n = (int)f.size();
    std::vector<std::pair<int, T>> nonzero;
    for (int i = 1; i < n; ++i) {
        if (f[i] != T()) {
            nonzero.emplace_back(i, f[i]);
        }
    }
    std::vector<T> g(n);
    T inv_f0 = T(1) / f[0];
    g[0] = inv_f0;
    for (int i = 1; i < n; ++i) {
        for (auto [j, val] : nonzero) {
            if (j > i) {
                break;
            }
            g[i] -= g[i - j] * val;
        }
        g[i] *= inv_f0;
    }
    return g;
}
