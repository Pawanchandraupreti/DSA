// Find the length of the longest increasing subsequence

#include <bits/stdc++.h>
using namespace std;

int longestIncreasingSubsequenceLength(const vector<int>& arr) {
    if (arr.empty()) return 0;

    vector<int> tails(arr.size(), 0);
    int length = 1;
    tails[0] = arr[0];

    for (int i = 1; i < (int)arr.size(); ++i) {
        int value = arr[i];
        auto it = lower_bound(tails.begin(), tails.begin() + length, value);

        if (it == tails.begin() + length) {
            tails[length] = value;
            ++length;
        } else {
            *it = value;
        }
    }

    return length;
}

int main() {
    int n;
    if (!(cin >> n)) return 0;

    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    cout << longestIncreasingSubsequenceLength(arr);
    return 0;
}


