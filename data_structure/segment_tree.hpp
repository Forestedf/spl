#pragma once

#include <cassert>
#include <utility>
#include <vector>
#include "operations.hpp"

template <typename Monoid>
class SegmentTree {
public:
    using Value = typename Monoid::Value;

private:
    int old_length;
    int length;
    std::vector<Value> node;

    static int ceil2(int n) {
        int l = 1;
        while (l < n) {
            l <<= 1;
        }
        return l;
    }

public:
    SegmentTree(int n)
        : old_length(n),
          length(ceil2(old_length)),
          node(length << 1, Monoid::id()) {
        assert(n >= 0);
    }

    SegmentTree(const std::vector<Value> &v)
        : old_length((int)v.size()),
          length(ceil2(old_length)),
          node(length << 1, Monoid::id()) {
        for (int i = 0; i < old_length; ++i) {
            node[i + length] = v[i];
        }
        for (int i = length - 1; i > 0; --i) {
            node[i] = Monoid::op(node[i << 1], node[i << 1 | 1]);
        }
    }

    template <typename F>
    SegmentTree(int n, const F &f)
        : old_length(n), length(ceil2(n)), node(length << 1, Monoid::id()) {
        assert(n >= 0);
        for (int i = 0; i < old_length; ++i) {
            node[i + length] = f(i);
        }
        for (int i = length - 1; i > 0; --i) {
            node[i] = Monoid::op(node[i << 1], node[i << 1 | 1]);
        }
    }

    const Value &operator[](int idx) const {
        assert(idx >= 0 && idx < old_length);
        return node[idx + length];
    }

    void update(int idx, Value val) {
        assert(idx >= 0 && idx < old_length);
        idx += length;
        node[idx] = std::move(val);
        while (idx != 1) {
            idx >>= 1;
            node[idx] = Monoid::op(node[idx << 1], node[idx << 1 | 1]);
        }
    }

    Value prod(int l, int r) const {
        assert(l >= 0 && l <= r && r <= old_length);
        Value prodl = Monoid::id();
        Value prodr = Monoid::id();
        l += length;
        r += length;
        while (l != r) {
            if (l & 1) {
                prodl = Monoid::op(prodl, node[l++]);
            }
            if (r & 1) {
                prodr = Monoid::op(node[--r], prodr);
            }
            l >>= 1;
            r >>= 1;
        }
        return Monoid::op(prodl, prodr);
    }

    Value all_prod() const { return node[1]; }
};
