#define PROBLEM "https://judge.yosupo.jp/problem/inverse_matrix"
#include "../../template/template.hpp"
#include "../../template/fastio.hpp"
#include "../../algebra/inverse_matrix.hpp"
#include "../../number_theory/mod_int.hpp"

int main() {
    using M = ModInt<998244353>;
    i32 n;
    rd.read(n);
    Matrix<M> a(n);
    REP(i, n) REP(j, n) {
        rd.read(a(i, j).val);
    }
    optional<Matrix<M>> b = inverse_matrix(a);
    if (b.has_value()) {
        REP(i, n) REP(j, n) {
            wr.write(b->operator()(i, j).val);
            wr.write(" \n"[j + 1 == n]);
        }
    } else {
        wr.writeln(-1);
    }
}
