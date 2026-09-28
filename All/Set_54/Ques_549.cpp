// Kth Smallest Element in a BST

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int value;
    Node* left;
    Node* right;
};

void inorder(Node* root, vector<int> &values) {
    if (!root) return;
    inorder(root->left, values);
    values.push_back(root->value);
    inorder(root->right, values);
}

int main() {
    Node* root = new Node{5, new Node{3, new Node{2, nullptr, nullptr}, new Node{4, nullptr, nullptr}}, new Node{7, nullptr, new Node{8, nullptr, nullptr}}};
    int k;
    cin >> k;
    vector<int> values;
    inorder(root, values);
    cout << values[k - 1] << '\n';
    return 0;
}
