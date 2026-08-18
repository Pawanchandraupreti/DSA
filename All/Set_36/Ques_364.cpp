// Maximum subarray sum using Kadane's algorithm

#include <bits/stdc++.h>
using namespace std;

int maxSubarraySum(const vector<int>& arr) {
    int current = arr[0];
    int best = arr[0];

    for (int i = 1; i < (int)arr.size(); ++i) {
        current = max(arr[i], current + arr[i]);
        best = max(best, current);
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

    cout << maxSubarraySum(arr);
    return 0;
}
