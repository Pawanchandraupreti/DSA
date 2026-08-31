// Binary Tree Closest Value

#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    explicit TreeNode(int value) : val(value), left(nullptr), right(nullptr) {}
};

int closestValue(TreeNode* root, double target) {
    int closest = root->val;
    TreeNode* current = root;

    while (current) {
        if (abs(current->val - target) < abs(closest - target)) {
            closest = current->val;
        }

        if (target < current->val) {
            current = current->left;
        } else {
            current = current->right;
        }
    }

    return closest;
}

TreeNode* buildTree() {
    int value;
    cin >> value;
    if (value == -1) return nullptr;

    TreeNode* node = new TreeNode(value);
    node->left = buildTree();
    node->right = buildTree();
    return node;
}

int main() {
    TreeNode* root = buildTree();
    double target;
    cin >> target;

    cout << closestValue(root, target);
    return 0;
}

