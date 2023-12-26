#pragma once

#include <cassert>
#include <vector>

template <typename Monoid>
class SegmentTreeXorRange {
public:
    using Value = typename Monoid::Value;

private:
    static int floor_log2(int n) { return 31 - __builtin_clz(n); }

    int depth;
    std::vector<std::vector<Value>> node;

public:
    SegmentTreeXorRange(const std::vector<Value> &a)
        : depth(floor_log2((int)a.size())), node(2 * (int)a.size()) {
        assert(!a.empty());
        assert((int)a.size() == (1 << depth));
        for (int i = 0; i < (int)a.size(); ++i) {
            node[a.size() + i] = {a[i]};
        }
        for (int i = (int)a.size() - 1; i > 0; --i) {
            int k = (int)node[2 * i].size();
            node[i].resize(2 * k);
            for (int j = 0; j < k; ++j) {
                node[i][j] = Monoid::op(node[2 * i][j], node[2 * i + 1][j]);
                node[i][j + k] = Monoid::op(node[2 * i + 1][j], node[2 * i][j]);
            }
        }
    }

    Value prod(int l, int r, int x) const {
        assert(l >= 0 && l <= r && r <= (1 << depth));
        int d = depth;
        int nodel_prefix = l;
        int noder_prefix = r;
        l += 1 << depth;
        r += 1 << depth;
        Value lp = Monoid::id();
        Value rp = Monoid::id();
        while (l < r) {
            int x_upper = x >> (depth - d);
            int x_lower = x ^ (x_upper << (depth - d));
            if (l % 2 == 1) {
                int nodei = (x_upper ^ nodel_prefix) + (1 << d);
                lp = Monoid::op(lp, node[nodei][x_lower]);
                ++l;
                ++nodel_prefix;
            }
            if (r % 2 == 1) {
                --r;
                --noder_prefix;
                int nodei = (x_upper ^ noder_prefix) + (1 << d);
                rp = Monoid::op(node[nodei][x_lower], rp);
            }
            --d;
            l /= 2;
            nodel_prefix /= 2;
            r /= 2;
            noder_prefix /= 2;
        }
        return Monoid::op(lp, rp);
    }
};
