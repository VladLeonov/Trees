#include "myPriorityQueue.h"
#include <queue>

myPriorityQueue.const_iterator myPriorityQueue::find(const T&val) const {
    auto first = this->c.cbegin();
    auto last = this->c.cend();
    while (first!=last) {
        if (*first==val) return first;
        ++first;
    }
    return last;
}
