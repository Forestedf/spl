#define PROBLEM "https://judge.yosupo.jp/problem/bitwise_xor_convolution"
#include "../../bit/xor_convolution.hpp"
#include "../../number_theory/mod_int.hpp"
#include "../../template/template.hpp"

int main() {
    using M = ModInt<998244353>;
    I32(n);
    V<M> a(1 << n), b(1 << n);
    REP(i, 1 << n) {
        cin >> a[i];
    }
    REP(i, 1 << n) {
        cin >> b[i];
    }
    V<M> c = bitwise_xor_convolution(a, b);
    REP(i, 1 << n) {
        cout << c[i] << " \n"[i + 1 == (1 << n)];
    }
}
