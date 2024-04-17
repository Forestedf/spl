#define PROBLEM "https://judge.yosupo.jp/problem/matrix_rank"
#include "../../template/template.hpp"
#include "../../template/fastio.hpp"
#include "../../algebra/rank_of_matrix.hpp"
#include "../../number_theory/mod_int.hpp"

int main() {
    using M = ModInt<998244353>;
    i32 n, m;
    rd.read(n, m);
    Matrix<M> a(n, m);
    REP(i, n) REP(j, m) {
        rd.read(a(i, j).val);
    }
    wr.writeln(rank_of_matrix(a));
}
