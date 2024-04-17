#define PROBLEM "https://judge.yosupo.jp/problem/matrix_det"
#include "../../template/template.hpp"
#include "../../template/fastio.hpp"
#include "../../algebra/determinant.hpp"
#include "../../number_theory/mod_int.hpp"

int main() {
    using M = ModInt<998244353>;
    i32 n;
    rd.read(n);
    Matrix<M> a(n);
    REP(i, n) REP(j, n) {
        rd.read(a(i, j).val);
    }
    wr.writeln(determinant(a).val);
}
