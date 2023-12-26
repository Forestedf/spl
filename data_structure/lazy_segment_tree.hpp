#pragma once

#include <cassert>
#include <utility>
#include <vector>

template <typename MonoidFunc>
class LazySegmentTree {
public:
    using Value = typename MonoidFunc::Value;
    using Func = typename MonoidFunc::Func;

private:
    int old_length;
    int lg;
    int length;
    std::vector<Value> values;
    std::vector<Func> funcs;

    static int lg2(int n) {
        int x = 1;
        int l = 0;
        while (x < n) {
            x <<= 1;
            ++l;
        }
        return l;
    }

    void _apply(int idx, const Func &func) {
        values[idx] = MonoidFunc::apply(func, values[idx]);
        funcs[idx] = MonoidFunc::composite(func, funcs[idx]);
    }

    void push(int idx) {
        _apply(idx << 1, funcs[idx]);
        _apply(idx << 1 | 1, funcs[idx]);
        funcs[idx] = MonoidFunc::func_id();
    }

    void recalc_values(int idx) {
        values[idx] = MonoidFunc::op(values[idx << 1], values[idx << 1 | 1]);
    }

public:
    LazySegmentTree(int n)
        : old_length(n),
          lg(lg2(n)),
          length(1 << lg),
          values(length << 1, MonoidFunc::id()),
          funcs(length << 1, MonoidFunc::func_id()) {
        assert(n >= 0);
    }

    LazySegmentTree(const std::vector<Value> &v)
        : old_length((int)v.size()),
          lg(lg2(old_length)),
          length(1 << lg),
          values(length << 1, MonoidFunc::id()),
          funcs(length << 1, MonoidFunc::func_id()) {
        for (int i = 0; i < old_length; ++i) {
            values[i + length] = v[i];
        }
        for (int i = length - 1; i > 0; --i) {
            recalc_values(i);
        }
    }

    template <typename F>
    LazySegmentTree(int n, const F &f)
        : old_length(n),
          lg(lg2(n)),
          length(1 << lg),
          values(length << 1, MonoidFunc::id()),
          funcs(length << 1, MonoidFunc::func_id()) {
        for (int i = 0; i < old_length; ++i) {
            values[i + length] = f(i);
        }
        for (int i = length - 1; i > 0; --i) {
            recalc_values(i);
        }
    }

    void update(int idx, Value val) {
        assert(idx >= 0 && idx < old_length);
        idx += length;
        for (int i = lg; i > 0; --i) {
            push(idx >> i);
        }
        values[idx] = std::move(val);
        while (idx >>= 1) {
            recalc_values(idx);
        }
    }

    void apply(int l, int r, const Func &func) {
        assert(l >= 0 && l <= r && r <= old_length);
        if (l == r) {
            return;
        }
        l += length;
        r += length;
        int _l = l;
        int _r = r;
        for (int i = lg; i > 0; --i) {
            push(_l >> i);
            push((_r - 1) >> i);
        }
        while (l < r) {
            if (l & 1) {
                _apply(l++, func);
            }
            if (r & 1) {
                _apply(--r, func);
            }
            l >>= 1;
            r >>= 1;
        }
        for (int i = 1; i <= lg; ++i) {
            if ((_l >> i << i) != _l) {
                recalc_values(_l >> i);
            }
            if ((_r >> i << i) != _r) {
                recalc_values((_r - 1) >> i);
            }
        }
    }

    Value prod(int l, int r) {
        assert(l >= 0 && l <= r && r <= old_length);
        if (l == r) {
            return MonoidFunc::id();
        }
        l += length;
        r += length;
        for (int i = lg; i > 0; --i) {
            push(l >> i);
            push((r - 1) >> i);
        }
        Value lp = MonoidFunc::id();
        Value rp = MonoidFunc::id();
        while (l < r) {
            if (l & 1) {
                lp = MonoidFunc::op(lp, values[l++]);
            }
            if (r & 1) {
                rp = MonoidFunc::op(values[--r], rp);
            }
            l >>= 1;
            r >>= 1;
        }
        return MonoidFunc::op(lp, rp);
    }

    Value all_prod() const { return values[1]; }
};
