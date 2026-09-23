// Lowest Common Ancestor in a BST

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int value;
    Node* left;
    Node* right;
};

int main() {
    Node* root = new Node{6, new Node{2, new Node{0, nullptr, nullptr}, new Node{4, nullptr, nullptr}}, new Node{8, new Node{7, nullptr, nullptr}, new Node{9, nullptr, nullptr}}};
    int a, b;
    cin >> a >> b;

    while (root) {
        if (a < root->value && b < root->value) root = root->left;
        else if (a > root->value && b > root->value) root = root->right;
        else break;
    }

    cout << (root ? root->value : -1) << '\n';
    return 0;
}
