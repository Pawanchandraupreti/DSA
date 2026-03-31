// Check if Binary Tree is Balanced

#include <iostream>
#include <cmath>
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

int height(Node* root) {
    if(root == NULL) return 0;

    int lh = height(root->left);
    if(lh == -1) return -1;

    int rh = height(root->right);
    if(rh == -1) return -1;

    if(abs(lh - rh) > 1) return -1;

    return 1 + max(lh, rh);
}

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->left->left = new Node(3);

    if(height(root) == -1)
        cout << "Not Balanced";
    else
        cout << "Balanced";
}


