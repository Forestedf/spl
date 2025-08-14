#define PROBLEM "https://judge.yosupo.jp/problem/lcm_convolution"
#include "../../convolution/lcm_convolution.hpp"
#include "../../number_theory/mod_int.hpp"
#include "../../template/fastio.hpp"
#include "../../template/template.hpp"

void solve() {
    using M = ModInt<998244353>;
    i32 n;
    rd.read(n);
    V<M> a(n + 1), b(n + 1);
    REP(i, 1, n + 1) {
        rd.read(a[i].val);
    }
    REP(i, 1, n + 1) {
        rd.read(b[i].val);
    }
    V<M> c = lcm_convolution(a, b);
    REP(i, 1, n + 1) {
        wr.write(c[i].val);
        if (i != n) {
            wr.write(' ');
        }
    }
    wr.writeln();
}

int main() {
    i32 t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
}
