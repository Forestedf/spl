#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A"
#include "../../number_theory/dynamic_mod_int.hpp"
#include "../../template/template.hpp"
#include "../../template/random.hpp"

using M = DynamicModInt<0>;

void test() {
    u32 m = uniform(1u, 1u << 31);
    M::set_mod(m);
    REP(iter, 10'000'000) {
        u32 x = uniform(1u << 31);
        u32 y = uniform(1u << 31);
        M a(x);
        M b(y);
        assert((a + b).val == (x + y) % m);
        assert((a - b).val == safe_mod((i64)x - (i64)y, (i64)m));
        assert((a * b).val == 1ull * x * y % m);
    }
}

int main() {
    REP(i, 10) {
        test();
    }
    cout << "Hello World\n";
}
