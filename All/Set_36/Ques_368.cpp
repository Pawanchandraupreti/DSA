// Find the length of the longest consecutive sequence

#include <bits/stdc++.h>
using namespace std;

int longestConsecutiveSequence(const vector<int>& arr) {
    unordered_set<int> values(arr.begin(), arr.end());
    int best = 0;

    for (int value : values) {
        if (!values.count(value - 1)) {
            int current = value;
            int length = 1;

            while (values.count(current + 1)) {
                ++current;
                ++length;
            }

            best = max(best, length);
        }
    }

    return best;
}

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    cout << longestConsecutiveSequence(arr);
    return 0;
}
