#define PROBLEM "https://judge.yosupo.jp/problem/system_of_linear_equations"
#include "../../template/template.hpp"
#include "../../template/fastio.hpp"
#include "../../algebra/system_of_linear_equations.hpp"
#include "../../number_theory/mod_int.hpp"

int main() {
    using M = ModInt<998244353>;
    i32 n, m;
    rd.read(n, m);
    VV<M> a(n, V<M>(m));
    REP(i, n) REP(j, m) {
        rd.read(a[i][j].val);
    }
    V<M> b(n);
    REP(i, n) {
        rd.read(b[i].val);
    }
    optional<pair<V<M>, VV<M>>> ans = linear_equations(n, m, a, b);
    if (ans.has_value()) {
        auto [c, d] = *ans;
        wr.writeln(LEN(d));
        REP(i, m) {
            wr.write(c[i].val);
            wr.write(" \n"[i + 1 == m]);
        }
        REP(i, LEN(d)) REP(j, m) {
            wr.write(d[i][j].val);
            wr.write(" \n"[j + 1 == m]);
        }
    } else {
        wr.writeln(-1);
    }
}
