#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A"
#define FAST_IO
#define FIX_SEED

#include "../../template/template.hpp"
#include "../../template/random.hpp"
#include "../../number_theory/frac_binsearch.hpp"

#include <compare>

struct Rational {
    i64 num, den;
    Rational() : num(0), den(1) {}
    Rational(i64 n, i64 d) : num(n), den(d) {
        assert(den != 0);
        i64 g = gcd(num, den);
        num /= g;
        den /= g;
        if (den < 0) {
            num = -num;
            den = -den;
        }
    }
    friend auto operator<=>(Rational lhs, Rational rhs) -> std::strong_ordering {
        return lhs.num * rhs.den <=> rhs.num * lhs.den;
    }
    friend bool operator==(Rational lhs, Rational rhs) {
        return lhs.num * rhs.den == rhs.num * lhs.den;
    }
};

void test() {
    constexpr i32 B = 1000;
    V<Rational> rats;
    REP(num, 1, B + 1) {
        REP(den, num + 1, B + 1) {
            if (gcd(num, den) == 1) {
                rats.push_back(Rational(num, den));
            }
        }
    }
    rats.push_back(Rational(0, 1));
    rats.push_back(Rational(1, 1));
    sort(ALL(rats));
    constexpr i64 C = 1'000'000'000'000'000;
    REP(i, 100000) {
        i64 c = (uniform(2) ? B + 1 : C + 1);
        i64 num = uniform(1LL, c + 1);
        i64 den = uniform(1LL, c + 1);
        while (num == den) {
            num = uniform(1LL, c + 1);
            den = uniform(1LL, c + 1);
        }
        if (num > den) {
            swap(num, den);
        }
        Rational r(num, den);
        // >=r
        {
            auto [a, b] = get_lim_true(B, [&](i32 x, i32 y) -> bool {
                return Rational(x, y) >= r;
            });
            auto it = lower_bound(ALL(rats), r);
            assert(Rational(a, b) == *it);
        }
        // <=r
        {
            auto [a, b] = get_lim_true(B, [&](i32 x, i32 y) -> bool {
                return Rational(x, y) <= r;
            });
            auto it = upper_bound(ALL(rats), r) - 1;
            assert(Rational(a, b) == *it);
        }
        // >r
        {
            auto [a, b] = get_lim_true(B, [&](i32 x, i32 y) -> bool {
                return Rational(x, y) > r;
            });
            auto it = upper_bound(ALL(rats), r);
            assert(Rational(a, b) == *it);
        }
        // <r
        {
            auto [a, b] = get_lim_true(B, [&](i32 x, i32 y) -> bool {
                return Rational(x, y) < r;
            });
            auto it = lower_bound(ALL(rats), r) - 1;
            assert(Rational(a, b) == *it);
        }
    }
}

int main() {
    test();
    cout << "Hello World\n";
}
