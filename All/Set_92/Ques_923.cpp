// Longest Common Prefix

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<string> a(n);
    for (string &s : a) cin >> s;

    string ans = a[0];
    for (int i = 1; i < n; i++) {
        int j = 0;
        while (j < (int)ans.size() && j < (int)a[i].size() && ans[j] == a[i][j]) j++;
        ans.resize(j);
    }
    cout << ans << '\n';
    return 0;
}
