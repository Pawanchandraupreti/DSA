// Inorder Successor in BST

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

Node* insertNode(Node* root, int key) {
    if(root == NULL) return new Node(key);

    if(key < root->val)
        root->left = insertNode(root->left, key);
    else
        root->right = insertNode(root->right, key);

    return root;
}

Node* inorderSuccessor(Node* root, int key) {
    Node* succ = NULL;

    while(root) {
        if(key < root->val) {
            succ = root;
            root = root->left;
        }
        else {
            root = root->right;
        }
    }

    return succ;
}

int main() {
    Node* root = NULL;
    int values[] = {20, 8, 22, 4, 12, 10, 14};

    for(int x : values)
        root = insertNode(root, x);

    int key = 10;
    Node* ans = inorderSuccessor(root, key);

    if(ans) cout << ans->val;
    else cout << "No Successor";
}