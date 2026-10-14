// Binary Tree Level Order Traversal

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> tree(n);
    for (int &x : tree) cin >> x;

    queue<int> q;
    if (n > 0 && tree[0] != -1) q.push(0);
    while (!q.empty()) {
        int levelSize = q.size();
        while (levelSize--) {
            int index = q.front();
            q.pop();
            cout << tree[index] << ' ';
            int left = 2 * index + 1, right = 2 * index + 2;
            if (left < n && tree[left] != -1) q.push(left);
            if (right < n && tree[right] != -1) q.push(right);
        }
        cout << '| ';
    }
    cout << '\n';
    return 0;
}