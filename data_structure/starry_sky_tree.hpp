#pragma once

#include <algorithm>
#include <vector>

template <typename T>
class StarrySkyTree {
    int old_len;
    int len;
    std::vector<T> nodes;

    static int ceil2(int n) {
        int l = 1;
        while (l < n) {
            l <<= 1;
        }
        return l;
    }

    void balance(int idx) {
        T mx = std::max(nodes[idx << 1], nodes[idx << 1 | 1]);
        nodes[idx] += mx;
        nodes[idx << 1] -= mx;
        nodes[idx << 1 | 1] -= mx;
    }

public:
    StarrySkyTree(int n) : old_len(n), len(ceil2(n)), nodes(len << 1, T(0)) {}

    void add(int l, int r, T v) {
        assert(l >= 0 && l <= r && r <= old_len);
        l += len;
        r += len;
        int l_ = l;
        int r_ = r;
        while (l < r) {
            if (l & 1) {
                nodes[l++] += v;
            }
            if (r & 1) {
                nodes[--r] += v;
            }
            l >>= 1;
            r >>= 1;
        }
        for (int i = l_ >> 1; i > 0; i >>= 1) {
            balance(i);
        }
        for (int i = (r_ - 1) >> 1; i > 0; i >>= 1) {
            balance(i);
        }
    }

    T all_max() const { return nodes[1]; }
};
