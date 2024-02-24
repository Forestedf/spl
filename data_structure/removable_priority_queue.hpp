#pragma once
#include <cassert>
#include <queue>
template <typename T, typename Comp = std::less<T>>
class RemovablePriorityQueue {
    std::priority_queue<T, std::vector<T>, Comp> pq, rem;
    void remove_() {
        while (!pq.empty() && !rem.empty() && pq.top() == rem.top()) {
            pq.pop();
            rem.pop();
        }
    }
public:
    RemovablePriorityQueue(Comp comp = Comp()) : pq(comp), rem(comp) {}
    void push(T x) {
        pq.push(x);
    }
    void remove(T x) {
        rem.push(x);
    }
    T pop() {
        remove_();
        assert(!pq.empty());
        T ret = pq.top();
        pq.pop();
        return ret;
    }
    T top() {
        remove_();
        assert(!pq.empty());
        return pq.top();
    }
    int size() const {
        return (int)pq.size() - (int)rem.size();
    }
    bool empty() const {
        return size() == 0;
    }
};