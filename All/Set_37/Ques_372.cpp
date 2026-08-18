// Find the first index of a target in a sorted array

#include <bits/stdc++.h>
using namespace std;

int firstIndex(const vector<int>& arr, int target) {
    int left = 0;
    int right = (int)arr.size() - 1;
    int answer = -1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target) {
            answer = mid;
            right = mid - 1;
        } else if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return answer;
}

int main() {
    int n, target;
    cin >> n >> target;

    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    cout << firstIndex(arr, target);
    return 0;
}
