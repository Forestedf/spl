#pragma once

#include <cassert>
#include <stack>
#include <utility>

template <typename Monoid>
class SlidingWindowAggregation {
public:
    using Value = typename Monoid::Value;

private:
    std::stack<Value> st0;
    std::stack<Value> st1;
    Value st1_prod;

public:
    SlidingWindowAggregation()
        : st0({Monoid::id()}), st1({Monoid::id()}), st1_prod(Monoid::id()) {}

    void push(Value val) {
        st1_prod = Monoid::op(st1_prod, val);
        st1.emplace(std::move(val));
    }

    void pop() {
        if (st0.size() == 1) {
            while (st1.size() > 1) {
                st0.emplace(Monoid::op(st1.top(), st0.top()));
                st1.pop();
            }
            st1_prod = Monoid::id();
        }
        st0.pop();
    }

    int size() const { return (int)(st0.size() + st1.size() - 2); }

    bool empty() const { return size() == 0; }

    Value prod() const { return Monoid::op(st0.top(), st1_prod); }
};
