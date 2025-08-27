#define PROBLEM "https://judge.yosupo.jp/problem/min_plus_convolution_convex_convex"
#include "../min_plus_convolution.hpp"
#include "../../template/fastio.hpp"
#include "../../template/template.hpp"

void solve() {
    i32 n, m;
    rd.read(n, m);
    V<i32> a(n), b(m);
    REP(i, n) {
        rd.read(a[i]);
    }
    REP(i, m) {
        rd.read(b[i]);
    }
    V<i32> c = min_plus_convolution(a, b);
    REP(i, n + m - 1) {
        wr.write(c[i]);
        if (i == n + m - 2) {
            wr.writeln();
        } else {
            wr.write(' ');
        }
    }
}

int main() {
    i32 t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
}
