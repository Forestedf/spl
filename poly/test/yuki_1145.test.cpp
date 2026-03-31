#define PROBLEM "https://yukicoder.me/problems/no/1145"
#include "../../poly/rational_sum_1.hpp"
#include "../../template/template.hpp"

int main() {
    using M = ModInt<998244353>;
    I32(n, m);
    V<M> b(n);
    REP(i, n) {
        read(b[i].val);
    }
    V<M> a(n, M(1));
    V<M> c = rational_sum_1(a, b, m + 1);
    REP(i, 1, m + 1) {
        cout << c[i] << " \n"[i == m];
    }
}
