// Minimum Cost to Make Array Equal

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<long long> arr(n), cost(n);
    
    for (int i = 0; i < n; i++) cin >> arr[i];
    for (int i = 0; i < n; i++) cin >> cost[i];
    
    long long ans = LLONG_MAX;
    set<long long> vals(arr.begin(), arr.end());
    
    for (long long target : vals) {
        long long curr = 0;
        for (int i = 0; i < n; i++) {
            if (arr[i] < target) {
                curr += (target - arr[i]) * cost[i];
            } else if (arr[i] > target) {
                curr += (arr[i] - target) * cost[i];
            }
        }
        ans = min(ans, curr);
    }
    
    cout << ans;
    return 0;
}
