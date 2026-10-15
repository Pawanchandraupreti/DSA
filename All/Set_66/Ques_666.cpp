// Implement Stack Using Queue

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    queue<int> q;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        q.push(x);
        for (int j = 0; j < (int)q.size() - 1; j++) {
            q.push(q.front());
            q.pop();
        }
    }

    while (!q.empty()) {
        cout << q.front() << ' ';
        q.pop();
    }
    cout << '\n';
    return 0;
}

