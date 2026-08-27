// Merge K Sorted Arrays

#include <bits/stdc++.h>
using namespace std;

vector<int> mergeKSortedArrays(const vector<vector<int>>& arrays) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> result;

    for (int i = 0; i < (int)arrays.size(); ++i) {
        if (!arrays[i].empty()) {
            pq.push({arrays[i][0], i});
        }
    }

    vector<int> index(arrays.size(), 1);

    while (!pq.empty()) {
        auto [value, arrayIndex] = pq.top();
        pq.pop();
        result.push_back(value);

        if (index[arrayIndex] < (int)arrays[arrayIndex].size()) {
            pq.push({arrays[arrayIndex][index[arrayIndex]], arrayIndex});
            ++index[arrayIndex];
        }
    }

    return result;
}

int main() {
    int k;
    cin >> k;

    vector<vector<int>> arrays(k);
    for (int i = 0; i < k; ++i) {
        int m;
        cin >> m;
        arrays[i].resize(m);
        for (int j = 0; j < m; ++j) {
            cin >> arrays[i][j];
        }
    }

    vector<int> merged = mergeKSortedArrays(arrays);
    for (int value : merged) {
        cout << value << ' ';
    }

    return 0;
}