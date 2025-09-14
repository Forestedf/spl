#define PROBLEM "https://judge.yosupo.jp/problem/multipoint_evaluation"
#include "../../poly/multieval.hpp"
#include "../../template/template.hpp"
#include "../../template/fastio.hpp"

int main() {
    using M = ModInt<998244353>;
    i32 n, m;
    rd.read(n, m);
    V<M> c(n);
    REP(i, n) {
        rd.read(c[i].val);
    }
    V<M> p(m);
    REP(i, m) {
        rd.read(p[i].val);
    }
    V<M> ev = multieval(c, p);
    REP(i, m) {
        wr.write(ev[i].val);
        wr.write(" \n"[i + 1 == m]);
    }
}
