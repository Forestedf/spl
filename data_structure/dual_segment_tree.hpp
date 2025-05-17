#pragma once

#include <cassert>
#include <utility>
#include <vector>

template <typename MonoidFunc>
class DualSegmentTree {
public:
    using Func = typename MonoidFunc::Func;

private:
    int old_length;
    int lg;
    int length;
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

    void push(int idx) {
        funcs[idx << 1] = MonoidFunc::composite(funcs[idx], funcs[idx << 1]);
        funcs[idx << 1 | 1] = MonoidFunc::composite(funcs[idx], funcs[idx << 1 | 1]);
        funcs[idx] = MonoidFunc::func_id();
    }

public:
    DualSegmentTree(int n)
        : old_length(n),
          lg(lg2(n)),
          length(1 << lg),
          funcs(length << 1, MonoidFunc::func_id()) {
        assert(n >= 0);
    }

    Func get(int idx) {
        assert(idx >= 0 && idx < old_length);
        idx += length;
        for (int i = lg; i > 0; --i) {
            push(idx >> i);
        }
        return funcs[idx];
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
                funcs[l] = MonoidFunc::composite(func, funcs[l]);
                ++l;
            }
            if (r & 1) {
                --r;
                funcs[r] = MonoidFunc::composite(func, funcs[r]);
            }
            l >>= 1;
            r >>= 1;
        }
    }
};

template <typename MonoidFunc>
class DualSegmentTreeWithValues {
public:
    using Value = typename MonoidFunc::Value;
    using Func = typename MonoidFunc::Func;

private:
    int n;
    std::vector<Value> values;
    DualSegmentTree<MonoidFunc> seg;
    
public:
    DualSegmentTreeWithValues(std::vector<Value> vals) : n((int)vals.size()), values(std::move(vals)), seg(n) {}
    template <typename F>
    DualSegmentTreeWithValues(int n, F f) : n(n), values(n, MonoidFunc::id()), seg(n) {
        for (int i = 0; i < n; ++i) {
            values[i] = f(i);
        }
    }
    
    void apply(int l, int r, const Func &f) {
        seg.apply(l, r, f);
    }
    
    Value get(int idx) {
        Func f = seg.get(idx);
        return MonoidFunc::apply(f, values[idx]);
    }
};
