// Top K Frequent Elements

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    unordered_map<int, int> freq;
    vector<int> values(n);
    for (int i = 0; i < n; i++) {
        cin >> values[i];
        freq[values[i]]++;
    }
    vector<pair<int, int>> arr(freq.begin(), freq.end());
    sort(arr.begin(), arr.end(), [](auto &a, auto &b) {
        return a.second > b.second;
    });
    for (int i = 0; i < min(k, (int)arr.size()); i++) {
        cout << arr[i].first << ' ';
    }
    cout << '\n';
    return 0;
}
