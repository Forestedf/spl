#define PROBLEM \
    "https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A"
#define FAST_IO
#define FIX_SEED

#include "../../number_theory/montgomery_64.hpp"
#include "../../template/random.hpp"
#include "../../template/template.hpp"

using M = MontgomeryModInt64<0>;

u64 add(u64 a, u64 b, u64 m) { return (a + b) % m; }
u64 sub(u64 a, u64 b, u64 m) { return (m + a - b) % m; }
u64 mul(u64 a, u64 b, u64 m) { return __uint128_t(a) * b % m; }

void test_small_mod(i32 m) {
    M::set_mod(m);
    REP(i, m) REP(j, m) {
        M x(i), y(j);
        assert((x + y).val() == add(i, j, m));
        assert((x - y).val() == sub(i, j, m));
        assert((x * y).val() == mul(i, j, m));
    }
}

void test_large_mod(u64 m) {
    M::set_mod(m);

    constexpr int ITER = 1'000'000;

    for (int i = 0; i < ITER; ++i) {
        u64 x = uniform(m);
        u64 y = uniform(m);
        M x_(x), y_(y);
        assert((x_ + y_).val() == add(x, y, m));
        assert((x_ - y_).val() == sub(x, y, m));
        assert((x_ * y_).val() == mul(x, y, m));
    }
}

void test() {
    for (i32 m = 3; m <= 99; m += 2) {
        test_small_mod(m);
    }

    for (int i = 0; i < 10; ++i) {
        u64 m = uniform<u64>(3, 1ULL << 63);
        while (m % 2 == 0) {
            m = uniform<u64>(3, 1ULL << 63);
        }
        test_large_mod(m);
    }

    test_large_mod((1ULL << 63) - 1);
}

int main() {
    test();
    cout << "Hello World\n";
}
