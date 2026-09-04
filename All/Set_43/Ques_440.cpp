// Minimize Maximum Pair Sum

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    
    for (int i = 0; i < n; i++) cin >> arr[i];
    
    sort(arr.begin(), arr.end());
    
    int minMax = INT_MAX;
    for (int i = 0; i < n / 2; i++) {
        minMax = min(minMax, arr[i] + arr[n - 1 - i]);
    }
    
    cout << minMax;
    return 0;
}
