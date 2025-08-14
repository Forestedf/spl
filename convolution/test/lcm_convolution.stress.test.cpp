#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A"
#define FAST_IO
#define FIX_SEED

#include "../../number_theory/mod_int.hpp"
#include "../../convolution/lcm_convolution.hpp"
#include "../../template/random.hpp"
#include "../../template/template.hpp"

using M = ModInt<998244353>;

V<M> naive_convolution(const V<M> &a, const V<M> &b) {
    V<M> ret(max(LEN(a), LEN(b)));
    REP(i, 1, LEN(a)) REP(j, 1, LEN(b)) {
        i64 tmp = lcm(i64(i), i64(j));
        if (tmp < LEN(ret)) {
            ret[tmp] += a[i] * b[j];
        }
    }
    return ret;
}

void test() {
    constexpr i32 NM_MAX = 500;
    i32 n = uniform(NM_MAX + 1);
    i32 m = uniform(NM_MAX + 1);
    V<M> a(n), b(m);
    REP(i, n) { a[i].val = uniform(M::get_mod()); }
    REP(i, m) { b[i].val = uniform(M::get_mod()); }
    V<M> c = naive_convolution(a, b);
    V<M> d = lcm_convolution(a, b);
    assert(c == d);
}

void small_test() {
    constexpr i32 NM_MAX = 10;
    i32 n = uniform(NM_MAX + 1);
    i32 m = uniform(NM_MAX + 1);
    V<M> a(n), b(m);
    REP(i, n) { a[i].val = uniform(M::get_mod()); }
    REP(i, m) { b[i].val = uniform(M::get_mod()); }
    V<M> c = naive_convolution(a, b);
    V<M> d = lcm_convolution(a, b);
    assert(c == d);
}

void zero_test() {
    constexpr i32 NM_MAX = 5;
    REP(n, NM_MAX + 1) REP(m, NM_MAX + 1) {
        V<M> a(n), b(m);
        REP(i, n) { a[i].val = uniform(M::get_mod()); }
        REP(i, m) { b[i].val = uniform(M::get_mod()); }
        V<M> c = naive_convolution(a, b);
        V<M> d = lcm_convolution(a, b);
        assert(c == d);
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
