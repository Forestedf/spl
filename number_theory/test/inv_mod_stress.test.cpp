#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A"
#define FAST_IO
#define FIX_SEED

#include "../../template/template.hpp"
#include "../../template/random.hpp"
#include "../../number_theory/utils.hpp"

void test() {
    constexpr int ITER = 1'000'000;
    for (int t = 0; t < ITER; ++t) {
        int a = uniform(1, 1'000'000'000);
        int b = uniform(1, 1'000'000'000);
        while (gcd(a, b) != 1) {
            a = uniform(1, 1'000'000'000);
            b = uniform(1, 1'000'000'000);
        }
        int c = inv_mod(a, b);
        assert((long long)a * c % b == 1 && 0 <= c && c < b);
    }
}

int main() {
    test();
    cout << "Hello World\n";
}
