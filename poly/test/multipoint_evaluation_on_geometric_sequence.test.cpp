#define PROBLEM "https://judge.yosupo.jp/problem/multipoint_evaluation_on_geometric_sequence"
#include "../../poly/multieval_geometric.hpp"
#include "../../template/template.hpp"
#include "../../template/fastio.hpp"

int main() {
    using M = ModInt<998244353>;
    i32 n, m;
    M a, r;
    rd.read(n, m, a.val, r.val);
    V<M> c(n);
    REP(i, n) {
        rd.read(c[i].val);
    }
    V<M> ev = multieval_geometric(c, m, a, r);
    REP(i, m) {
        wr.write(ev[i].val);
        wr.write(" \n"[i + 1 == m]);
    }
}
