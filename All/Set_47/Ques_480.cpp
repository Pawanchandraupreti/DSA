// Binary Tree Maximum Path Sum

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int val;
    Node* left;
    Node* right;
};

int dfs(Node* root, int &ans) {
    if (!root) return 0;
    int left = max(0, dfs(root->left, ans));
    int right = max(0, dfs(root->right, ans));
    ans = max(ans, root->val + left + right);
    return root->val + max(left, right);
}

int main() {
    Node* root = new Node{1, new Node{2, nullptr, nullptr}, new Node{3, nullptr, nullptr}};
    int ans = INT_MIN;
    dfs(root, ans);
    cout << ans << '\n';
    return 0;
}

