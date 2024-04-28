#pragma once
#include <optional>
#include <utility>
template <typename T>
std::optional<std::pair<std::vector<T>, std::vector<std::vector<T>>>>
linear_equations(int n, int m, std::vector<std::vector<T>> a, std::vector<T> b) {
    assert((int)a.size() == n);
    for (int i = 0; i < n; ++i) {
        assert((int)a[i].size() == m);
    }
    assert((int)b.size() == n);
    int li = 0;
    std::vector<int> spe(m, -1);
    for (int i = 0; li < n && i < m; ++i) {
        int row = -1;
        for (int j = li; j < n; ++j) {
            if (a[j][i] != T()) {
                row = j;
                break;
            }
        }
        if (row == -1) {
            continue;
        }
        std::swap(a[row], a[li]);
        std::swap(b[row], b[li]);
        T inv = a[li][i].inv();
        for (int j = 0; j < m; ++j) {
            a[li][j] *= inv;
        }
        b[li] *= inv;
        for (int j = 0; j < n; ++j) {
            if (j == li) {
                continue;
            }
            T cf = a[j][i];
            for (int k = 0; k < m; ++k) {
                a[j][k] -= a[li][k] * cf;
            }
            b[j] -= b[li] * cf;
        }
        spe[i] = li++;
    }
    for (int i = li; i < n; ++i) {
        if (b[i] != T()) {
            return std::nullopt;
        }
    }
    std::vector<T> ans(m, T());
    std::vector<std::vector<T>> basis(m - li, std::vector<T>(m, T()));
    int ph = 0;
    for (int i = 0; i < m; ++i) {
        if (spe[i] != -1) {
            ans[i] = b[spe[i]];
        } else {
            basis[ph][i] = T(1);
            for (int j = 0; j < i; ++j) {
                if (int r = spe[j]; r != -1) {
                    basis[ph][j] = -a[r][i];
                }
            }
            ++ph;
        }
    }
    return std::make_pair(ans, basis);
}
