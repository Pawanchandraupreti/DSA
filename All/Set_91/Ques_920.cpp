// Level Order Traversal of a Binary Tree

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> left(n, -1), right(n, -1);
    vector<int> child(n);
    for (int i = 0; i < n; i++) {
        cin >> left[i] >> right[i];
        if (left[i] != -1) child[left[i]] = 1;
        if (right[i] != -1) child[right[i]] = 1;
    }
    int root = 0;
    while (child[root]) root++;
    queue<int> q;
    q.push(root);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        cout << u << ' ';
        if (left[u] != -1) q.push(left[u]);
        if (right[u] != -1) q.push(right[u]);
    }
    cout << '\n';
    return 0;
}
