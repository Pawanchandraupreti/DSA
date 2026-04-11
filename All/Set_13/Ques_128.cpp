// Binary Tree Vertical Order Traversal

#include <iostream>
#include <map>
#include <queue>
#include <vector>
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

    map<int, vector<int>> mp;
    queue<pair<Node*, int>> q;
    q.push({root, 0});

    while(!q.empty()) {
        Node* cur = q.front().first;
        int hd = q.front().second;
        q.pop();

        mp[hd].push_back(cur->val);

        if(cur->left) q.push({cur->left, hd - 1});
        if(cur->right) q.push({cur->right, hd + 1});
    }

    for(auto x : mp) {
        for(int val : x.second)
            cout << val << " ";
    }
}
