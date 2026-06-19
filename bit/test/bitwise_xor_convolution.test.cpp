#define PROBLEM "https://judge.yosupo.jp/problem/bitwise_xor_convolution"
#include "../../bit/xor_convolution.hpp"
#include "../../number_theory/mod_int.hpp"
#include "../../template/template.hpp"
#include "../../template/fastio.hpp"

int main() {
    using M = ModInt<998244353>;
    i32 n;
    rd.read(n);
    V<M> a(1 << n), b(1 << n);
    REP(i, 1 << n) {
        rd.read(a[i].val);
    }
    REP(i, 1 << n) {
        rd.read(b[i].val);
    }
    V<M> c = bitwise_xor_convolution(a, b);
    REP(i, 1 << n) {
        wr.writeln(c[i].val);
    }
}
