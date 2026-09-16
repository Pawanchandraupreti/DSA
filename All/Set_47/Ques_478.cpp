// Count Distinct Subarrays

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &x : a) cin >> x;

    unordered_map<int, int> mp;
    long long ans = 0;
    int left = 0;
    for (int right = 0; right < n; right++) {
        mp[a[right]]++;
        while (mp.size() > 2) {
            mp[a[left]]--;
            if (mp[a[left]] == 0) mp.erase(a[left]);
            left++;
        }
        ans += right - left + 1;
    }

    cout << ans << '\n';
    return 0;
}
