#pragma once

#include <algorithm>
#include <limits>
#include <utility>

template <typename T>
struct Add {
    using Value = T;
    static Value id() { return T(0); }
    static Value op(const Value &lhs, const Value &rhs) { return lhs + rhs; }
    static Value inv(const Value &x) { return -x; }
};

template <typename T>
struct Mul {
    using Value = T;
    static Value id() { return Value(1); }
    static Value op(const Value &lhs, const Value &rhs) { return lhs * rhs; }
    static Value inv(const Value &x) { return Value(1) / x; }
};

template <typename T>
struct Min {
    static_assert(std::numeric_limits<T>::is_specialized);
    using Value = T;
    static Value id() { return std::numeric_limits<T>::max(); }
    static Value op(const Value &lhs, const Value &rhs) {
        return std::min(lhs, rhs);
    }
};

template <typename T>
struct Max {
    static_assert(std::numeric_limits<T>::is_specialized);
    using Value = T;
    static Value id() { return std::numeric_limits<Value>::min(); }
    static Value op(const Value &lhs, const Value &rhs) {
        return std::max(lhs, rhs);
    }
};

template <typename T>
struct Xor {
    using Value = T;
    static Value id() { return T(0); }
    static Value op(const Value &lhs, const Value &rhs) { return lhs ^ rhs; }
    static Value inv(const Value &x) { return x; }
};

template <typename Monoid>
struct Reversible {
    using Value = std::pair<typename Monoid::Value, typename Monoid::Value>;
    static Value id() { return Value(Monoid::id(), Monoid::id()); }
    static Value op(const Value &v1, const Value &v2) {
        return Value(Monoid::op(v1.first, v2.first),
                     Monoid::op(v2.second, v1.second));
    }
};
