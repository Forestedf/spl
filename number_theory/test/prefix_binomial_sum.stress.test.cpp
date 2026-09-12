#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A"
#include "../../number_theory/mod_int.hpp"
#include "../../number_theory/prefix_binomial_sum.hpp"
#include "../../number_theory/factorial.hpp"
#include "../../template/template.hpp"
#include "../../template/random.hpp"

using M = ModInt<998244353>;

void test(int n) {
    BinomialPrefixSum<M> sums(n);
    for (int m = 0; m <= n; ++m) {
        M s;
        for (int k = 0; k <= m; ++k) {
            s += binom<M>(m, k);
            assert(sums.get(m, k) == s);
        }
    }
}

int main() {
    test(3333);
    cout << "Hello World\n";
}
