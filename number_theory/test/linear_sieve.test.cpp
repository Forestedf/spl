#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A"
#include "../../number_theory/linear_sieve.hpp"
#include "../../number_theory/factorize.hpp"
#include "../../template/template.hpp"
#include "../../template/random.hpp"

void test() {
    constexpr i32 N = 100000;
    LinearSieve sieve(N);
    REP(i, 1, N + 1) {
        V<pi> f1 = sieve.factorize(i);
        V<u64> f2 = factorize(i);
        V<u64> ps;
        for (auto [p, e] : f1) {
            while (e--) {
                ps.push_back(p);
            }
        }
        assert(ps == f2);
    }
}

int main() {
    cout << "Hello World\n";
}
