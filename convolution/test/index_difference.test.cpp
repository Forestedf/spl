#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A"
#define FAST_IO
#define FIX_SEED

#include "../../convolution/index_difference.hpp"
#include "../../template/random.hpp"
#include "../../template/template.hpp"

using M = ModInt<998244353>;

void test() {
    constexpr i32 NM_MAX = 500;
    i32 n = uniform(NM_MAX + 1);
    i32 m = uniform(NM_MAX + 1);
    V<M> a(n), b(m);
    REP(i, n) { a[i].val = uniform(M::get_mod()); }
    REP(i, m) { b[i].val = uniform(M::get_mod()); }
    V<M> c(n && m ? n : 0);
    REP(i, n) REP(j, m) {
        if (i - j >= 0) {
            c[i - j] += a[i] * b[j];
        }
    }
    V<M> d = convolve_diff(a, b);
    assert(c == d);
}

void small_test() {
    constexpr i32 NM_MAX = 10;
    i32 n = uniform(NM_MAX + 1);
    i32 m = uniform(NM_MAX + 1);
    V<M> a(n), b(m);
    REP(i, n) { a[i].val = uniform(M::get_mod()); }
    REP(i, m) { b[i].val = uniform(M::get_mod()); }
    V<M> c(n && m ? n : 0);
    REP(i, n) REP(j, m) {
        if (i - j >= 0) {
            c[i - j] += a[i] * b[j];
        }
    }
    V<M> d = convolve_diff(a, b);
    assert(c == d);
}

void zero_test() {
    constexpr i32 NM_MAX = 5;
    REP(n, NM_MAX + 1) {
        i32 m = 0;
        V<M> a(n), b(m);
        REP(i, n) { a[i].val = uniform(M::get_mod()); }
        REP(i, m) { b[i].val = uniform(M::get_mod()); }
        V<M> c(n && m ? n : 0);
        REP(i, n) REP(j, m) {
            if (i - j >= 0) {
                c[i - j] += a[i] * b[j];
            }
        }
        V<M> d = convolve_diff(a, b);
    }
    REP(m, NM_MAX + 1) {
        i32 n = 0;
        V<M> a(n), b(m);
        REP(i, n) { a[i].val = uniform(M::get_mod()); }
        REP(i, m) { b[i].val = uniform(M::get_mod()); }
        V<M> c(n && m ? n : 0);
        REP(i, n) REP(j, m) {
            if (i - j >= 0) {
                c[i - j] += a[i] * b[j];
            }
        }
        V<M> d = convolve_diff(a, b);
    }
}

int main() {
    constexpr i32 ITER = 1000;
    REP(i, ITER) {
        test();
        small_test();
    }
    zero_test();
    cout << "Hello World\n";
}
