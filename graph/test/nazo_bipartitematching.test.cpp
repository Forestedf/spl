#define PROBLEM "https://judge.yosupo.jp/problem/bipartitematching"
#define FAST_IO
#include "../../graph/nazo_bipartite_matching.hpp"
#include "../../template/fastio.hpp"
#include "../../template/template.hpp"

void solve() {
    i32 l, r, m;
    rd.read(l, r, m);
    V<pi> es(m);
    for (auto &[a, b] : es) {
        rd.read(a, b);
    }
    V<i32> ml = bipartite_matching(l, r, es).first;
    i32 k = l - count(ALL(ml), -1);
    wr.writeln(k);
    REP(i, l) {
        if (ml[i] != -1) {
            wr.writeln(i, ml[i]);
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
