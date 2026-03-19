#define PROBLEM "https://judge.yosupo.jp/problem/compositional_inverse_of_formal_power_series_large"
#include "../../poly/compositional_inverse.hpp"
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
    std::vector<M> g = compositional_inverse(f);
    REP(i, n) {
        wr.writeln(g[i].val);
    }
}
