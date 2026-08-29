// Median from Data Stream

#include <bits/stdc++.h>
using namespace std;

class MedianFinder {
private:
    priority_queue<int> smallerHalf;
    priority_queue<int, vector<int>, greater<int>> largerHalf;

public:
    void addNum(int number) {
        if (smallerHalf.empty() || number <= smallerHalf.top()) {
            smallerHalf.push(number);
        } else {
            largerHalf.push(number);
        }

        if (smallerHalf.size() > largerHalf.size() + 1) {
            largerHalf.push(smallerHalf.top());
            smallerHalf.pop();
        } else if (largerHalf.size() > smallerHalf.size()) {
            smallerHalf.push(largerHalf.top());
            largerHalf.pop();
        }
    }

    double findMedian() {
        if (smallerHalf.size() > largerHalf.size()) {
            return smallerHalf.top();
        }
        return (smallerHalf.top() + largerHalf.top()) / 2.0;
    }
};

int main() {
    int operations;
    cin >> operations;

    MedianFinder finder;
    while (operations--) {
        string command;
        cin >> command;
        if (command == "add") {
            int number;
            cin >> number;
            finder.addNum(number);
        } else {
            cout << fixed << setprecision(1) << finder.findMedian() << ' ';
        }
    }
    return 0;
}

