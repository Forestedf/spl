#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A"
#define FAST_IO
#define FIX_SEED

#include "../../template/template.hpp"
#include "../../template/random.hpp"
#include "../../number_theory/ax_by_c.hpp"

void test() {
    constexpr int ITER = 1'000'000;
    for (int t = 0; t < ITER; ++t) {
        i64 a = uniform(-1'000'000, 1'000'000);
        i64 b = uniform(-1'000'000, 1'000'000);
        i64 c = uniform(-1'000'000, 1'000'000);
        optional<pair<i64, i64>> ret = ax_by_c(a, b, c);
        if (ret.has_value()) {
            auto [x, y] = *ret;
            assert(a * x + b * y == c);
            if (a && b && c) {
                assert(abs(x) <= abs(b * c));
                assert(abs(y) <= abs(a * c));
            }
        }
    }
    for (int a = -50; a <= 50; ++a) {
        for (int b = -50; b <= 50; ++b) {
            for (int c = -50; c <= 50; ++c) {
                optional<pair<i32, i32>> ret = ax_by_c(a, b, c);
                if (ret.has_value()) {
                    auto [x, y] = *ret;
                    assert(a * x + b * y == c);
                    if (a && b && c) {
                        assert(abs(x) <= abs(b * c));
                        assert(abs(y) <= abs(a * c));
                    }
                }
            }
        }
    }
}

int main() {
    test();
    cout << "Hello World\n";
}
