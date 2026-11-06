// Minimum Cost to Connect Sticks

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    priority_queue<int, vector<int>, greater<int>> heap;
    for (int i = 0; i < n; i++) { int x; cin >> x; heap.push(x); }
    int answer = 0;
    while (heap.size() > 1) {
        int first = heap.top(); heap.pop();
        int second = heap.top(); heap.pop();
        answer += first + second;
        heap.push(first + second);
    }
    cout << answer << '\n';
    return 0;
}
