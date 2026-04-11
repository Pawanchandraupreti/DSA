// Find Median from Data Stream (Two Heaps)

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class MedianFinder {
    priority_queue<int> leftMax;
    priority_queue<int, vector<int>, greater<int>> rightMin;

public:
    void addNum(int num) {
        if(leftMax.empty() || num <= leftMax.top())
            leftMax.push(num);
        else
            rightMin.push(num);

        if(leftMax.size() > rightMin.size() + 1) {
            rightMin.push(leftMax.top());
            leftMax.pop();
        }
        else if(rightMin.size() > leftMax.size()) {
            leftMax.push(rightMin.top());
            rightMin.pop();
        }
    }

    double findMedian() {
        if(leftMax.size() == rightMin.size()) {
            return (leftMax.top() + rightMin.top()) / 2.0;
        }
        return leftMax.top();
    }
};

int main() {
    MedianFinder mf;
    vector<int> nums = {5, 15, 1, 3};

    for(int x : nums) {
        mf.addNum(x);
        cout << mf.findMedian() << " ";
    }
}
