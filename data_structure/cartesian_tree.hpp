#pragma once

#include <vector>

template <typename T, typename Compare = std::less<T>>
std::vector<int> cartesian_tree(const std::vector<T> &a, Compare comp = Compare()) {
    std::vector<int> stc;
    std::vector<int> par(a.size(), -1);
    for (int i = 0; i < a.size(); ++i) {
        while (stc.size() >= 2 && comp(a[i], a[stc.back()])) {
            if (comp(a[i], a[stc[stc.size() - 2]])) {
                par[stc.back()] = stc[stc.size() - 2];
            } else {
                par[stc.back()] = i;
            }
            stc.pop_back();
        }
        if (stc.size() == 1 && comp(a[i], a[stc.back()])) {
            par[stc.back()] = i;
            stc.pop_back();
        }
        stc.push_back(i);
    }
    while (stc.size() >= 2) {
        par[stc.back()] = stc[stc.size() - 2];
        stc.pop_back();
    }
    return par;
}