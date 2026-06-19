#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A"
#include "../../template/template.hpp"
#include "../../template/random.hpp"
#include "../../algebra/determinant.hpp"
#include "../../algebra/division_free_determinant.hpp"
#include "../../number_theory/mod_int.hpp"

int main() {
    using M = ModInt<998244353>;
    REP(n, 50) {
        Matrix<M> mat(n);
        REP(i, n) REP(j, n) {
            mat(i, j) = M(uniform(M::get_mod()));
        }
        M det = determinant(mat);
        M div_free = division_free_determinant(mat);
        assert(det == div_free);
    }
    cout << "Hello World\n";
}
