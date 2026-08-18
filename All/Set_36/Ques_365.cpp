// Find the missing number in a sorted array from 1 to n+1

#include <bits/stdc++.h>
using namespace std;

int missingNumber(const vector<int>& arr) {
    int left = 0;
    int right = (int)arr.size() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == mid + 1) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return left + 1;
}

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    cout << missingNumber(arr);
    return 0;
}
