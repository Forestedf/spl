#define PROBLEM "https://judge.yosupo.jp/problem/queue_operate_all_composite"
#define FAST_IO

#include "../../data_structure/sliding_window_aggregation.hpp"
#include "../../number_theory/mod_int.hpp"
#include "../../template/template.hpp"

using Mint = ModInt<998244353>;

struct Linear {
    Mint a, b;
    Linear() : a(Mint(1)), b(Mint(0)) {}
    Linear(Mint _a, Mint _b) : a(_a), b(_b) {}
    Mint operator()(Mint x) { return a * x + b; }
};

// f \circ g
Linear composite(const Linear &f, const Linear &g) {
    return Linear(f.a * g.a, f.a * g.b + f.b);
}

struct Ops {
    using Value = Linear;
    static Value id() { return Linear(); }
    static Value op(const Value &x, const Value &y) { return composite(y, x); }
};

int main() {
    i32 q;
    cin >> q;
    SlidingWindowAggregation<Ops> swag;
    REP(qi, q) {
        i32 type;
        cin >> type;
        if (type == 0) {
            Linear f;
            cin >> f.a >> f.b;
            swag.push(f);
        } else if (type == 1) {
            swag.pop();
        } else {
            Mint x;
            cin >> x;
            cout << swag.prod()(x) << '\n';
        }
    }
}