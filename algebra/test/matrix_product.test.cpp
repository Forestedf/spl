#define PROBLEM "https://judge.yosupo.jp/problem/matrix_product"
#define FAST_IO
#include "../../template/template.hpp"
#include "../../template/fastio.hpp"
#include "../../algebra/matrix.hpp"
#include "../../number_theory/mod_int.hpp"

int main() {
    using M = ModInt<998244353>;
    i32 n, m, k;
    rd.read(n, m, k);
    Matrix<M> a(n, m), b(m, k);
    REP(i, n) REP(j, m) {
        rd.read(a(i, j).val);
    }
    REP(i, m) REP(j, k) {
        rd.read(b(i, j).val);
    }
    a *= b;
    REP(i, n) REP(j, k) {
        wr.write(a(i, j).val);
        wr.write(" \n"[j + 1 == k]);
    }
}
