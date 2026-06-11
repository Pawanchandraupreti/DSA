// Count subarrays with sum divisible by k

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    if (!(cin >> n >> k)) return 0;
    vector<ll> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];

    vector<long long> freq(k, 0);
    freq[0] = 1;
    ll pref = 0, ans = 0;
    for (ll x : a) {
        pref += x;
        int r = (int)((pref % k + k) % k);
        ans += freq[r];
        ++freq[r];
    }
    cout << ans;
    return 0;
}


