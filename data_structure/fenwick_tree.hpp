#pragma once

#include <cassert>
#include <vector>
#include "operations.hpp"

template <typename CommutativeGroup>
class FenwickTree {
public:
    using Value = typename CommutativeGroup::Value;

private:
    std::vector<Value> data;

public:
    FenwickTree(int n) : data(n, CommutativeGroup::id()) {}

    void add(int idx, const Value &x) {
        assert(idx >= 0 && idx < (int)data.size());
        for (; idx < (int)data.size(); idx |= idx + 1) {
            data[idx] = CommutativeGroup::op(data[idx], x);
        }
    }

    Value sum(int r) const {
        assert(r >= 0 && r <= (int)data.size());
        Value ret = CommutativeGroup::id();
        for (; r > 0; r &= r - 1) {
            ret = CommutativeGroup::op(ret, data[r - 1]);
        }
        return ret;
    }

    Value sum(int l, int r) const {
        assert(l >= 0 && l <= r && r <= (int)data.size());
        return CommutativeGroup::op(sum(r), CommutativeGroup::inv(sum(l)));
    }
};

template <typename T>
using FenwickTreeAdd = FenwickTree<Add<T>>;