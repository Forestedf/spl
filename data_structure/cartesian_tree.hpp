#pragma once

#include <tuple>
#include <vector>

// root: minimum element
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

// (root, lch, rch)
// root: minimum element
template <typename T, typename Compare = std::less<T>>
std::tuple<int, std::vector<int>, std::vector<int>> cartesian_tree_all(
    const std::vector<T> &a,
    Compare comp = Compare()
) {
    std::vector<int> par = cartesian_tree(a, comp);
    std::vector<int> lch(a.size(), -1), rch(a.size(), -1);
    int root = -1;
    for (int i = 0; i < (int)par.size(); ++i) {
        if (par[i] == -1) {
            root = i;
        } else if (par[i] < i) {
            rch[par[i]] = i;
        } else {
            lch[par[i]] = i;
        }
    }
    return std::make_tuple(root, lch, rch);
}
