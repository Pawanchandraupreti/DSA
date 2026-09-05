// Find All Duplicates in Array

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    
    for (int i = 0; i < n; i++) cin >> arr[i];
    
    vector<int> result;
    for (int i = 0; i < n; i++) {
        int idx = abs(arr[i]) - 1;
        if (arr[idx] < 0) {
            result.push_back(abs(arr[i]));
        } else {
            arr[idx] = -arr[idx];
        }
    }
    
    for (int x : result) cout << x << ' ';
    return 0;
}


