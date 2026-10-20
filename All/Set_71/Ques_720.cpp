// Merge K Sorted Arrays

#include <bits/stdc++.h>
using namespace std;

int main() {
    int k, size;
    cin >> k >> size;
    vector<vector<int>> arrays(k, vector<int>(size));
    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> heap;
    for (int i = 0; i < k; i++) {
        for (int &x : arrays[i]) cin >> x;
        if (size) heap.push({arrays[i][0], i, 0});
    }
    while (!heap.empty()) {
        auto [value, array, index] = heap.top();
        heap.pop();
        cout << value << ' ';
        if (index + 1 < size) heap.push({arrays[array][index + 1], array, index + 1});
    }
    cout << '\n';
    return 0;
}
