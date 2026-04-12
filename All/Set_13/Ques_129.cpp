// Deserialize Binary Tree (Preorder with Null Markers)

#include <iostream>
#include <vector>
#include <string>
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

TreeNode* deserialize(vector<string>& data, int& idx) {
    if(idx >= data.size() || data[idx] == "#") {
        idx++;
        return NULL;
    }

    TreeNode* root = new TreeNode(stoi(data[idx++]));
    root->left = deserialize(data, idx);
    root->right = deserialize(data, idx);
    return root;
}

void inorder(TreeNode* root) {
    if(root == NULL) return;
    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}

int main() {
    vector<string> data = {"1", "2", "#", "#", "3", "4", "#", "#", "#"};
    int idx = 0;

    TreeNode* root = deserialize(data, idx);
    inorder(root);
}


