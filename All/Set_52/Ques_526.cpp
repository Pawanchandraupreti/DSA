// Merge K Sorted Lists

#include <bits/stdc++.h>
using namespace std;

int main() {
    int k;
    cin >> k;
    priority_queue<int, vector<int>, greater<int>> heap;
    for (int i = 0; i < k; i++) {
        int n;
        cin >> n;
        for (int j = 0; j < n; j++) {
            int x;
            cin >> x;
            heap.push(x);
        }
    }

    while (!heap.empty()) {
        cout << heap.top() << ' ';
        heap.pop();
    }
    cout << '\n';
    return 0;
}
