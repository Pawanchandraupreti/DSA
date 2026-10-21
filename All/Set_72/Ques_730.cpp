// Binary Tree Right Side View

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> tree(n);
    for (int &x : tree) cin >> x;
    queue<int> q;
    if (n && tree[0] != -1) q.push(0);
    while (!q.empty()) {
        int last = -1, size = q.size();
        while (size--) {
            int node = q.front();
            q.pop();
            last = tree[node];
            int left = 2 * node + 1, right = 2 * node + 2;
            if (left < n && tree[left] != -1) q.push(left);
            if (right < n && tree[right] != -1) q.push(right);
        }
        cout << last << ' ';
    }
    cout << '\n';
    return 0;
}
