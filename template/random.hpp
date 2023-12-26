#pragma once
#include <chrono>
#include <random>

#if defined(LOCAL) || defined(FIX_SEED)
std::mt19937_64 mt(123456789);
#else
std::mt19937_64 mt(std::chrono::steady_clock::now().time_since_epoch().count());
#endif

template <typename T>
T uniform(T l, T r) {
    return std::uniform_int_distribution<T>(l, r - 1)(mt);
}
template <typename T>
T uniform(T n) {
    return std::uniform_int_distribution<T>(0, n - 1)(mt);
}