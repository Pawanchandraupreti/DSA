// Binary Tree Level Order Traversal

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int value;
    Node* left;
    Node* right;
};

int main() {
    Node* root = new Node{1, new Node{2, new Node{4, nullptr, nullptr}, new Node{5, nullptr, nullptr}}, new Node{3, nullptr, nullptr}};
    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        Node* cur = q.front();
        q.pop();
        cout << cur->value << ' ';
        if (cur->left) q.push(cur->left);
        if (cur->right) q.push(cur->right);
    }
    cout << '\n';
    delete root->left->left;
    delete root->left->right;
    delete root->left;
    delete root->right;
    delete root;
    return 0;
}
