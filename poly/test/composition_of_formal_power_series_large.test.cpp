#define PROBLEM "https://judge.yosupo.jp/problem/composition_of_formal_power_series_large"
#include "../../poly/composition.hpp"
#include "../../template/template.hpp"
#include "../../template/fastio.hpp"

int main() {
    using M = ModInt<998244353>;
    i32 n;
    rd.read(n);
    std::vector<M> f(n);
    REP(i, n) {
        rd.read(f[i].val);   
    }
    std::vector<M> g(n);
    REP(i, n) {
        rd.read(g[i].val);
    }
    std::vector<M> h = compose(f, g);
    assert(LEN(h) == n);
    REP(i, n) {
        wr.writeln(h[i].val);
    }
}
