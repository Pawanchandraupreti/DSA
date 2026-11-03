// Smallest Range Covering K Lists

#include <bits/stdc++.h>
using namespace std;

int main() {
    int k, size;
    cin >> k >> size;
    vector<vector<int>> lists(k, vector<int>(size));
    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> heap;
    int maximum = INT_MIN;
    for (int i = 0; i < k; i++) {
        for (int &x : lists[i]) cin >> x;
        heap.push({lists[i][0], i, 0});
        maximum = max(maximum, lists[i][0]);
    }
    int bestLeft = get<0>(heap.top()), bestRight = maximum;
    while (true) {
        auto [value, list, index] = heap.top();
        heap.pop();
        if (maximum - value < bestRight - bestLeft) bestLeft = value, bestRight = maximum;
        if (index + 1 == size) break;
        heap.push({lists[list][index + 1], list, index + 1});
        maximum = max(maximum, lists[list][index + 1]);
    }
    cout << bestLeft << ' ' << bestRight << '\n';
    return 0;
}
