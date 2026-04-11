// Diameter of Binary Tree

#include <iostream>
#include <algorithm>
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

int height(Node* root, int& dia) {
    if(root == NULL) return 0;

    int lh = height(root->left, dia);
    int rh = height(root->right, dia);

    dia = max(dia, lh + rh);
    return 1 + max(lh, rh);
}

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    int diameter = 0;
    height(root, diameter);

    cout << diameter;
}
