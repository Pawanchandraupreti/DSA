// Number of Distinct Values in Every Window

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int &x : a) cin >> x;
    unordered_map<int, int> cnt;
    for (int i = 0; i < k; i++) cnt[a[i]]++;
    cout << cnt.size() << ' ';
    for (int i = k; i < n; i++) {
        if (--cnt[a[i - k]] == 0) cnt.erase(a[i - k]);
        cnt[a[i]]++;
        cout << cnt.size() << ' ';
    }
    cout << '\n';
    return 0;
}
