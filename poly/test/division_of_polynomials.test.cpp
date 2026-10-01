#define PROBLEM "https://judge.yosupo.jp/problem/division_of_polynomials"
#include "../../poly/division.hpp"
#include "../../template/template.hpp"
#include "../../template/fastio.hpp"

int main() {
    using M = ModInt<998244353>;
    i32 n, m;
    rd.read(n, m);
    std::vector<M> f(n), g(m);
    REP(i, n) {
        rd.read(f[i].val);
    }
    REP(i, m) {
        rd.read(g[i].val);
    }
    auto [q, r] = poly_div(f, g);
    wr.writeln(LEN(q), LEN(r));
    REP(i, LEN(q)) {
        if (i) {
            wr.write(' ');
        }
        wr.write(q[i].val);
    }
    wr.writeln();
    REP(i, LEN(r)) {
        if (i) {
            wr.write(' ');
        }
        wr.write(r[i].val);
    }
    wr.writeln();
}
