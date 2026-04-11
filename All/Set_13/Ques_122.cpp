// Binary Tree Zigzag Level Order Traversal

#include <iostream>
#include <vector>
#include <queue>
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

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    queue<Node*> q;
    q.push(root);
    bool leftToRight = true;

    while(!q.empty()) {
        int sz = q.size();
        vector<int> level(sz);

        for(int i = 0; i < sz; i++) {
            Node* cur = q.front();
            q.pop();

            int idx = leftToRight ? i : (sz - 1 - i);
            level[idx] = cur->val;

            if(cur->left) q.push(cur->left);
            if(cur->right) q.push(cur->right);
        }

        leftToRight = !leftToRight;

        for(int x : level)
            cout << x << " ";
    }
}
