// Count Subarrays with Xor Equal to K

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    
    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];
    
    unordered_map<int, int> mp;
    mp[0] = 1;
    int xor_val = 0, cnt = 0;
    
    for (int i = 0; i < n; i++) {
        xor_val ^= arr[i];
        if (mp.find(xor_val ^ k) != mp.end()) {
            cnt += mp[xor_val ^ k];
        }
        mp[xor_val]++;
    }
    
    cout << cnt;
    return 0;
}


