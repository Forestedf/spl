#pragma once
#include <cassert>
#include <iostream>
#include <numeric>
template <typename T>
struct Rational {
    T num, den;
    Rational() : num(0), den(1) {}
    Rational(T x) : num(x), den(1) {}
    Rational(T n, T d) : num(n), den(d) {
        T g = std::gcd(num, den);
        num /= g;
        den /= g;
        if (den < 0) {
            num = -num;
            den = -den;
        }
    }
    static Rational<T> raw(T num, T den) {
        Rational<T> ret;
        ret.num = num;
        ret.den = den;
        return ret;
    }
    friend Rational<T> operator+(const Rational<T> &lhs, const Rational<T> &rhs) {
        return Rational<T>(lhs.num * rhs.den + lhs.den * rhs.num, lhs.den * rhs.den);
    }
    friend Rational<T> operator-(const Rational<T> &lhs, const Rational<T> &rhs) {
        return Rational<T>(lhs.num * rhs.den - lhs.den * rhs.num, lhs.den * rhs.den);
    }
    friend Rational<T> operator*(const Rational<T> &lhs, const Rational<T> &rhs) {
        return Rational<T>(lhs.num * rhs.num, lhs.den * rhs.den);
    }
    friend Rational<T> operator/(const Rational<T> &lhs, const Rational<T> &rhs) {
        assert(rhs.num != T(0));
        return Rational<T>(lhs.num * rhs.den, lhs.den * rhs.num);
    }
    Rational<T> &operator+=(const Rational<T> &rhs) {
        *this = *this + rhs;
        return *this;
    }
    Rational<T> &operator-=(const Rational<T> &rhs) {
        *this = *this - rhs;
        return *this;
    }
    Rational<T> &operator*=(const Rational<T> &rhs) {
        *this = *this * rhs;
        return *this;
    }
    Rational<T> &operator/=(const Rational<T> &rhs) {
        assert(rhs.num != T(0));
        *this = *this / rhs;
        return *this;
    }
    T cmp(const Rational<T> &rhs) const {
        return num * rhs.den - den * rhs.num;
    }
    friend bool operator==(const Rational<T> &lhs, const Rational<T> &rhs) {
        return lhs.cmp(rhs) == 0;
    }
    friend bool operator!=(const Rational<T> &lhs, const Rational<T> &rhs) {
        return lhs.cmp(rhs) != 0;
    }
    friend bool operator<(const Rational<T> &lhs, const Rational<T> &rhs) {
        return lhs.cmp(rhs) < 0;
    }
    friend bool operator>(const Rational<T> &lhs, const Rational<T> &rhs) {
        return lhs.cmp(rhs) > 0;
    }
    friend bool operator<=(const Rational<T> &lhs, const Rational<T> &rhs) {
        return lhs.cmp(rhs) <= 0;
    }
    friend bool operator>=(const Rational<T> &lhs, const Rational<T> &rhs) {
        return lhs.cmp(rhs) >= 0;
    }
};

template <typename T>
void debug(Rational<T> x) {
    std::cerr << x.num << '/' << x.den;
}
