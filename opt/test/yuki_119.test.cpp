#define PROBLEM "https://yukicoder.me/problems/no/119"
#include "../../opt/monge_min_cut.hpp"
#include "../../template/template.hpp"

int main() {
    I32(n);
    V<i32> b(n), c(n);
    REP(i, n) {
        read(b[i], c[i]);
    }
    I32(m)
    V<pi> edge(m);
    for (auto &[u, v] : edge) {
        read(u, v);
    }
    MongeMinCut<i32> mincut(V<i32>(n, 3), INF);
    REP(i, n) {
        V<i32> f(3, 0);
        f[0] = -b[i];
        f[2] = -c[i];
        mincut.add_1(i, f);
    }
    for (auto [u, v] : edge) {
        VV<i32> f(3, V<i32>(3, 0));
        f[0][2] = INF / m;
        mincut.add_2(u, v, f);
    }
    cout << -mincut.solve().first << '\n';
}