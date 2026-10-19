// Diameter of Binary Tree

#include <bits/stdc++.h>
using namespace std;

pair<int, int> diameter(int node, const vector<int> &tree) {
    if (node >= (int)tree.size() || tree[node] == -1) return {0, 0};
    auto left = diameter(2 * node + 1, tree);
    auto right = diameter(2 * node + 2, tree);
    int height = 1 + max(left.first, right.first);
    int best = max({left.second, right.second, left.first + right.first});
    return {height, best};
}

int main() {
    int n;
    cin >> n;
    vector<int> tree(n);
    for (int &x : tree) cin >> x;
    cout << diameter(0, tree).second << '\n';
    return 0;
}
