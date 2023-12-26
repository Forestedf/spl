#pragma once

#include <cassert>
#include <utility>
#include <vector>

class UnionFind {
    std::vector<int> par;

    int _root(int v) {
        if (par[v] < 0) {
            return v;
        } else {
            return par[v] = _root(par[v]);
        }
    }

public:
    UnionFind(int n) : par(n, -1) {}

    int root(int v) {
        assert(v >= 0 && v < (int)par.size());
        return _root(v);
    }

    int size(int v) {
        assert(v >= 0 && v < (int)par.size());
        return -par[_root(v)];
    }

    bool unite(int u, int v) {
        assert(u >= 0 && u < (int)par.size() && v >= 0 && v < (int)par.size());
        u = _root(u);
        v = _root(v);
        if (u == v) {
            return false;
        }
        if (par[u] < par[v]) {
            std::swap(u, v);
        }
        par[v] += par[u];
        par[u] = v;
        return true;
    }

    bool same(int u, int v) {
        assert(u >= 0 && u < (int)par.size() && v >= 0 && v < (int)par.size());
        return _root(u) == _root(v);
    }
};
