#pragma once

#include "fenwick_tree.hpp"

template <typename T>
class RangeAddRangeSum {
    int n;
    FenwickTree<Add<T>> ft;

public:
    RangeAddRangeSum(int n) : n(n), ft(n + 1) {}

    void add(int l, int r, const T &v) {
        assert(0 <= l && l <= r && r <= n);
        ft.add(l, v);
        ft.add(r, -v);
    }

    T sum(int idx) const {
        assert(0 <= idx && idx < n);
        return ft.sum(idx + 1);
    }
};