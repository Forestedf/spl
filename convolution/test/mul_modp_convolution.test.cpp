#define PROBLEM "https://judge.yosupo.jp/problem/mul_modp_convolution"
#include "../../convolution/mul_mod_p_conv.hpp"
#include "../../template/fastio.hpp"
#include "../../template/template.hpp"

void solve() {
    using M = ModInt<998244353>;
    i32 p;
    rd.read(p);
    V<M> a(p), b(p);
    REP(i, p) {
        rd.read(a[i].val);
    }
    REP(i, p) {
        rd.read(b[i].val);
    }
    V<M> c = mul_mod_p_convolution(a, b);
    REP(i, p) {
        wr.write(c[i].val);
        if (i != p - 1) {
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
