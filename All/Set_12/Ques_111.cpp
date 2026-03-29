// Lowest Common Ancestor (Binary Tree)

#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) {
        val = x;
        left = right = NULL;
    }
};

TreeNode* lca(TreeNode* root, int p, int q) {
    if(root == NULL || root->val == p || root->val == q)
        return root;

    TreeNode* left = lca(root->left, p, q);
    TreeNode* right = lca(root->right, p, q);

    if(left && right) return root;
    return left ? left : right;
}

int main() {
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(5);
    root->right = new TreeNode(1);
    root->left->left = new TreeNode(6);
    root->left->right = new TreeNode(2);

    TreeNode* ans = lca(root, 6, 2);
    cout << ans->val;
}


