// Kth Largest Stream Value

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    priority_queue<int, vector<int>, greater<int>> heap;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        heap.push(x);
        if ((int)heap.size() > k) heap.pop();
    }
    cout << heap.top() << '\n';
    return 0;
}
