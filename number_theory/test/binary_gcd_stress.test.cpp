#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A"
#define FAST_IO
#define FIX_SEED

#include "../../template/template.hpp"
#include "../../template/random.hpp"
#include "../../number_theory/binary_gcd.hpp"

void test() {
    constexpr int ITER = 1'000'000;
    for (int t = 0; t < ITER; ++t) {
        u64 a = mt();
        u64 b = mt();
        assert(gcd(a, b) == binary_gcd(a, b));
    }
    constexpr int RANGE = 1000;
    for (int i = 0; i < RANGE; ++i) {
        for (int j = 0; j < RANGE; ++j) {
            assert(gcd(i, j) == binary_gcd(i, j));
        }
    }
}

int main() {
    test();
    cout << "Hello World\n";
}
