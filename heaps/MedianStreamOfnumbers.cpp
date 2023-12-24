#include <queue>
#include <vector>

class MedianFinder {
public:
    std::priority_queue<int> maxheap; // this is smaller heap
    std::priority_queue<int, std::vector<int>, std::greater<int>> minheap;

    MedianFinder() {}

    void addNum(int num) {
        if (maxheap.empty() || maxheap.top() > num) {
            maxheap.push(num);
        } else {
            minheap.push(num);
        }

        if (maxheap.size() > minheap.size() + 1) {
            minheap.push(maxheap.top());
            maxheap.pop();
        } else if (minheap.size() > maxheap.size() + 1) {
            maxheap.push(minheap.top());
            minheap.pop();
        }
    }

    double findMedian() {
        if (maxheap.size() != minheap.size()) {
            if (maxheap.size() > minheap.size()) {
                return static_cast<double>(maxheap.top());
            } else {
                return static_cast<double>(minheap.top());
            }
        } else {
            return (static_cast<double>(maxheap.top()) + minheap.top()) / 2.0;
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
