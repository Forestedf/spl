#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A"
#define FAST_IO
#define FIX_SEED

#include "../../template/template.hpp"
#include "../../template/random.hpp"
#include "../../number_theory/utils.hpp"

void test(int a, int b) {
    auto [g, x, y] = extgcd2(a, b);
    assert(g == gcd(a, b));
    assert((long long)a * x + (long long)b * y == g);
    assert(0 <= x && x < b / g);
    assert(abs(y) < max(2, abs(a) / g));
}

void test() {
    constexpr int ITER = 1'000'000;
    for (int t = 0; t < ITER; ++t) {
        int a = uniform(-1'000'000'000, 1'000'000'000);
        int b = uniform(1, 1'000'000'000);
        test(a, b);
    }
    for (int a = -1000; a <= 1000; ++a) {
        for (int b = 1; b <= 1000; ++b) {
            test(a, b);
        }
    }
}

int main() {
    test();
    cout << "Hello World\n";
}
