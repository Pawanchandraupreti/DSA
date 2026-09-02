// Find K Largest Elements

#include <bits/stdc++.h>
using namespace std;

vector<int> findKLargest(vector<int>& numbers, int k) {
    priority_queue<int, vector<int>, greater<int>> minHeap;

    for (int number : numbers) {
        minHeap.push(number);
        if ((int)minHeap.size() > k) minHeap.pop();
    }

    vector<int> result;
    while (!minHeap.empty()) {
        result.push_back(minHeap.top());
        minHeap.pop();
    }

    sort(result.rbegin(), result.rend());
    return result;
}

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> numbers(n);
    for (int& number : numbers) cin >> number;

    for (int element : findKLargest(numbers, k)) {
        cout << element << ' ';
    }
    return 0;
}


