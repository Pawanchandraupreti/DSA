// Majority Element II

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    
    for (int i = 0; i < n; i++) cin >> arr[i];
    
    map<int, int> cnt;
    int threshold = n / 3;
    
    for (int x : arr) {
        cnt[x]++;
    }
    
    vector<int> res;
    for (auto [val, c] : cnt) {
        if (c > threshold) res.push_back(val);
    }
    
    sort(res.begin(), res.end());
    for (int x : res) cout << x << ' ';
    return 0;
}