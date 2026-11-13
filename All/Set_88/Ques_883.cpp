// K-th Smallest Number in a Subarray

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int left = 0, right = 0, count = 0;
};

vector<Node> tree(1);

int update(int previous, int left, int right, int position) {
    int current = tree.size();
    tree.push_back(tree[previous]);
    tree[current].count++;
    if (left != right) {
        int middle = (left + right) / 2;
        if (position <= middle) tree[current].left = update(tree[previous].left, left, middle, position);
        else tree[current].right = update(tree[previous].right, middle + 1, right, position);
    }
    return current;
}

int query(int oldRoot, int newRoot, int left, int right, int order) {
    if (left == right) return left;
    int middle = (left + right) / 2;
    int leftCount = tree[tree[newRoot].left].count - tree[tree[oldRoot].left].count;
    if (order <= leftCount) return query(tree[oldRoot].left, tree[newRoot].left, left, middle, order);
    return query(tree[oldRoot].right, tree[newRoot].right, middle + 1, right, order - leftCount);
}

int main() {
    int n, queries;
    cin >> n >> queries;
    vector<int> values(n), sorted;
    for (int &value : values) cin >> value;
    sorted = values;
    sort(sorted.begin(), sorted.end());
    sorted.erase(unique(sorted.begin(), sorted.end()), sorted.end());
    vector<int> roots(n + 1);
    for (int i = 0; i < n; i++) {
        int position = lower_bound(sorted.begin(), sorted.end(), values[i]) - sorted.begin();
        roots[i + 1] = update(roots[i], 0, sorted.size() - 1, position);
    }
    while (queries--) {
        int left, right, order;
        cin >> left >> right >> order;
        int position = query(roots[left - 1], roots[right], 0, sorted.size() - 1, order);
        cout << sorted[position] << '\n';
    }
    return 0;
}
