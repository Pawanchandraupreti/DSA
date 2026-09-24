// Diameter of a Binary Tree

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int value;
    Node* left;
    Node* right;
};

int height(Node* root, int &answer) {
    if (!root) return 0;
    int left = height(root->left, answer);
    int right = height(root->right, answer);
    answer = max(answer, left + right);
    return 1 + max(left, right);
}

int main() {
    Node* root = new Node{1, new Node{2, new Node{4, nullptr, nullptr}, new Node{5, nullptr, nullptr}}, new Node{3, nullptr, nullptr}};
    int answer = 0;
    height(root, answer);
    cout << answer << '\n';
    return 0;
}
