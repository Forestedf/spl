#pragma once

#include "utils.hpp"
#include <optional>

// solve a * x + b * y = c
// |x| <= |b * c|, |y| <= |a * c| (|a|, |b|, |c| > 0)
template <typename T>
std::optional<std::pair<T, T>> ax_by_c(T a, T b, T c) {
    if (c == 0) {
        return std::pair<T, T>(0, 0);
    }
    if (a == 0 && b == 0) {
        return std::nullopt;
    }
    if (a == 0) {
        if (c % b) {
            return std::nullopt;
        }
        return std::pair<T, T>(0, c / b);
    }
    if (b == 0) {
        if (c % a) {
            return std::nullopt;
        }
        return std::pair<T, T>(c / a, 0);
    }
    if (b < 0) {
        a = -a;
        b = -b;
        c = -c;
    }
    auto [g, x, y] = extgcd2(a, b);
    if (c % g) {
        return std::nullopt;
    }
    T mult = c / g;
    x *= mult;
    y *= mult;
    return std::pair<T, T>(x, y);
}
