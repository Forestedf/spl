#pragma once

#include <algorithm>
#include <cassert>
#include <utility>
#include <vector>
#include <functional>

template <typename T, typename F = std::less<T>>
class SparseTable {
    std::vector<std::vector<T>> table;
    int s;
    const F f;

    int log2(int n) const {
        return 31 - __builtin_clz(n);
    }
    
    T min2(const T &x, const T &y) const {
        if (f(x, y)) {
            return x;
        } else {
            return y;
        }
    }

public:
    SparseTable(std::vector<T> arr, const F &f = F()) : s((int) arr.size()), f(f) {
        if (s == 0) {
            return;
        }
        int m = log2(s);
        table.resize(m + 1);
        table[0] = std::move(arr);
        for (int i = 1; i <= m; ++i) {
            int w = 1 << i;
            table[i].resize(s - w + 1);
            for (int j = 0; j < (int) table[i].size(); ++j) {
                table[i][j] = min2(table[i - 1][j], table[i - 1][j + (w >> 1)]);
            }
        }
    }

    int size() const {
        return s;
    }

    // not empty
    T min(int l, int r) const {
        assert(l >= 0 && l < r && r <= s);
        int m = log2(r - l);
        return min2(table[m][l], table[m][r - (1 << m)]);
    }
};

