// Kth Smallest Element in BST

#include <iostream>
using namespace std;

struct Node {
    int val;
    Node* left;
    Node* right;

    Node(int x) {
        val = x;
        left = right = NULL;
    }
};

void inorder(Node* root, int& k, int& ans) {
    if(root == NULL) return;

    inorder(root->left, k, ans);

    k--;
    if(k == 0) {
        ans = root->val;
        return;
    }

    inorder(root->right, k, ans);
}

int main() {
    Node* root = new Node(5);
    root->left = new Node(3);
    root->right = new Node(6);
    root->left->left = new Node(2);
    root->left->right = new Node(4);

    int k = 3, ans = -1;
    inorder(root, k, ans);

    cout << ans;
}
