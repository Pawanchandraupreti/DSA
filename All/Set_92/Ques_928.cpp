// Merge Two Sorted Arrays

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(m);
    for (int &x : a) cin >> x;
    for (int &x : b) cin >> x;

    vector<int> ans;
    int i = 0, j = 0;
    while (i < n || j < m) {
        if (j == m || (i < n && a[i] <= b[j])) ans.push_back(a[i++]);
        else ans.push_back(b[j++]);
    }
    for (int x : ans) cout << x << ' ';
    cout << '\n';
    return 0;
}
