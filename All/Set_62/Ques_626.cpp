// Two Sum

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, target;
    cin >> n >> target;
    vector<int> a(n);
    for (int &x : a) cin >> x;

    unordered_map<int, int> mp;
    for (int i = 0; i < n; i++) {
        int need = target - a[i];
        if (mp.count(need)) {
            cout << mp[need] << ' ' << i << '\n';
            return 0;
        }
        mp[a[i]] = i;
    }
    cout << -1 << '\n';
    return 0;
}
