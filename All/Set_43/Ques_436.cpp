// Minimum Window Sorted Array

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    
    for (int i = 0; i < n; i++) cin >> arr[i];
    
    int left = 0, right = n - 1;
    while (left < n - 1 && arr[left] <= arr[left + 1]) left++;
    while (right > 0 && arr[right - 1] <= arr[right]) right--;
    
    if (left == n - 1) {
        cout << 0;
        return 0;
    }
    
    int minVal = INT_MAX, maxVal = INT_MIN;
    for (int i = left; i <= right; i++) {
        minVal = min(minVal, arr[i]);
        maxVal = max(maxVal, arr[i]);
    }
    
    while (left > 0 && arr[left - 1] > minVal) left--;
    while (right < n - 1 && arr[right + 1] < maxVal) right++;
    
    cout << right - left + 1;
    return 0;
}


