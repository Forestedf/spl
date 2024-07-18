#pragma once
#include <vector>
template <typename Cont>
std::vector<int> z_algorithm(const Cont &s) {
    std::vector<int> z(s.size(), s.size());
    int i = 1, j = 0;
    while (i < (int)s.size()) {
        while (i + j < (int)s.size() && s[i + j] == s[j]) {
            ++j;
        }
        z[i] = j;
        if (j == 0) {
            ++i;
            continue;
        }
        int k = 1;
        while (k < j && k + z[k] < j) {
            z[i + k] = z[k];
            ++k;
        }
        i += k;
        j -= k;
    }
    return z;
}
