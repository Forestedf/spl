#pragma once
#include <algorithm>
#include <numeric>
#include <utility>
// x -> clamp(x + a, b, c)
template <typename T>
struct Clamp {
    T a, b, c;
    Clamp() : a(0), b(-std::numeric_limits<T>::max() / 2), c(std::numeric_limits<T>::max() / 2) {}
    Clamp(T a, T b, T c) : a(a), b(b), c(c) {}
    T operator()(T x) const {
        return std::clamp(x + a, b, c);
    }
    std::pair<T, T> slope_range() const {
        return std::pair<T, T>(b - a, c - a);
    }
};
template <typename T>
Clamp<T> composite_clamps(const Clamp<T> &f, const Clamp<T> &g) {
    T a = f.a + g.a;
    T b = std::clamp(g.b + f.a, f.b, f.c);
    T c = std::clamp(g.c + f.a, f.b, f.c);
    return Clamp<T>(a, b, c);
}
template <typename T>
struct ClampMonoid {
    using Value = Clamp<T>;
    static Value id() {
        return Clamp<T>();
    }
    static Value op(const Value &f, const Value &g) {
        return composite_clamps(f, g);
    }
};
