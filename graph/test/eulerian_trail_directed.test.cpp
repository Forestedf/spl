#define PROBLEM "https://judge.yosupo.jp/problem/eulerian_trail_directed"
#define FAST_IO
#include "../../graph/eulerian_trail.hpp"
#include "../../template/template.hpp"
#include "../../template/fastio.hpp"

void solve() {
    i32 n, m;
    rd.read(n, m);
    Graph<i32, 1> g(n);
    REP(i, m) {
        i32 u, v;
        rd.read(u, v);
        g.add_edge(u, v);
    }
    g.build();
    auto [vs, es] = eulerian_trail(g);
    if (vs.empty()) {
        wr.writeln("No");
    } else {
        wr.writeln("Yes");
        REP(i, m + 1) {
            wr.write(vs[i]);
            wr.write(" \n"[i == m]);
        }
        REP(i, m) {
            wr.write(es[i]);
            wr.write(" \n"[i == m - 1]);
        }
        if (m == 0) {
            wr.writeln();
        }
    }
}

int main() {
    i32 t;
    rd.read(t);
    while (t--) {
        solve();
    }
}
