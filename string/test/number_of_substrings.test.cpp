#define PROBLEM "https://judge.yosupo.jp/problem/number_of_substrings"
#define FAST_IO

#include "../../template/template.hpp"
#include "../../string/suffix_automaton.hpp"

void solve() {
    STR(s);
    SuffixAutomaton sa;
    REP(i, LEN(s)) {
        sa.push(s[i]);
    }
    i64 ans = 0;
    REP(i, 1, LEN(sa.nodes)) {
        ans += sa.nodes[i].len - sa.nodes[sa.nodes[i].link].len;
    }
    cout << ans << '\n';
}

int main() {
    i32 t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
}
