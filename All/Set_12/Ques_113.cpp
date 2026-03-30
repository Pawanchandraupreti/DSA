// Serialize Binary Tree (Preorder)

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

void serialize(TreeNode* root) {
    if(root == NULL) {
        cout << "# ";
        return;
    }

    cout << root->val << " ";
    serialize(root->left);
    serialize(root->right);
}

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->right->left = new TreeNode(4);

    serialize(root);
}
