#include <queue>

using namespace std;

#ifndef MY_PRIORITY_QUEUE_H 
#define MY_PRIORITY_QUEUE_H


template<
    class T,
    class Container = vector<T>,
    class Compare = less<typename Container::value_type>
> class myPriorityQueue : public priority_queue<T, Container, Compare> {
	public:
    typedef typename
        priority_queue<
        T,
        Container,
        Compare>::container_type::const_iterator const_iterator;

    const_iterator find(const T&val) const {
        const_iterator first = this->c.begin();
        const_iterator last = this->c.end();
        while (first!=last) {
            if (*first==val) return first;
            ++first;
        }
        return last;
    }
    
    const_iterator end() {
    	return this->c.end();
	}
};

#endif //MY_PRIORITY_QUEUE_H
