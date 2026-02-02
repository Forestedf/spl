#define PROBLEM "https://judge.yosupo.jp/problem/polynomial_interpolation_on_geometric_sequence"
#include "../../poly/polynomial_interpolation_geometric.hpp"
#include "../../template/template.hpp"
#include "../../template/fastio.hpp"

int main() {
    using M = ModInt<998244353>;
    i32 n;
    M a, r;
    rd.read(n, a.val, r.val);
    V<M> y(n);
    REP(i, n) {
        rd.read(y[i].val);
    }
    V<M> f = polynomial_interpolation_geometric(y, a, r);
    REP(i, n) {
        wr.writeln(f[i].val);
    }
}
