// Segment Tree for Range Sum Queries

#include <bits/stdc++.h>
using namespace std;

class SegmentTree {
private:
    vector<long long> tree;
    int size;

    void build(const vector<int>& values, int node, int left, int right) {
        if (left == right) {
            tree[node] = values[left];
            return;
        }

        int middle = left + (right - left) / 2;
        build(values, node * 2, left, middle);
        build(values, node * 2 + 1, middle + 1, right);
        tree[node] = tree[node * 2] + tree[node * 2 + 1];
    }

    void update(int node, int left, int right, int index, int value) {
        if (left == right) {
            tree[node] = value;
            return;
        }

        int middle = left + (right - left) / 2;
        if (index <= middle) update(node * 2, left, middle, index, value);
        else update(node * 2 + 1, middle + 1, right, index, value);
        tree[node] = tree[node * 2] + tree[node * 2 + 1];
    }

    long long query(int node, int left, int right, int queryLeft, int queryRight) const {
        if (queryRight < left || right < queryLeft) return 0;
        if (queryLeft <= left && right <= queryRight) return tree[node];

        int middle = left + (right - left) / 2;
        return query(node * 2, left, middle, queryLeft, queryRight) +
               query(node * 2 + 1, middle + 1, right, queryLeft, queryRight);
    }

public:
    explicit SegmentTree(const vector<int>& values) : size((int)values.size()), tree(values.size() * 4) {
        build(values, 1, 0, size - 1);
    }

    void update(int index, int value) {
        update(1, 0, size - 1, index, value);
    }

    long long query(int left, int right) const {
        return query(1, 0, size - 1, left, right);
    }
};

int main() {
    int n, operations;
    cin >> n >> operations;

    vector<int> values(n);
    for (int& value : values) cin >> value;
    SegmentTree tree(values);

    while (operations--) {
        string command;
        cin >> command;
        if (command == "sum") {
            int left, right;
            cin >> left >> right;
            cout << tree.query(left, right) << ' ';
        } else if (command == "update") {
            int index, value;
            cin >> index >> value;
            tree.update(index, value);
        }
    }
    return 0;
}