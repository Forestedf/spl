#pragma once
#include "../number_theory/factorial.hpp"
#include "fps_inv.hpp"

template <typename T>
std::vector<T> fps_log(const std::vector<T> &f, int len = -1) {
    if (len == -1) {
        len = (int)f.size();
    }
    int n = (int)f.size();
    assert(n >= 1 && f[0] == T(1) && len >= 0);
    if (len == 0) {
        return std::vector<T>();
    }
    std::vector<T> df(std::min(n - 1, len - 1));
    for (int i = 0; i < (int)df.size(); ++i) {
        df[i] = f[i + 1] * T(i + 1);
    }
    std::vector<T> invf = fps_inv(f, len - 1);
    std::vector<T> ret = convolve(df, invf);
    ret.resize(len);
    for (int i = len - 1; i >= 1; --i) {
        ret[i] = ret[i - 1] * inv<T>(i);
    }
    ret[0] = T(0);
    return ret;
}
