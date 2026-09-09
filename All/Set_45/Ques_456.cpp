// Largest Divisible Subset

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int& x : a) cin >> x;
    sort(a.begin(), a.end());

    vector<int> dp(n, 1), parent(n, -1);
    int best = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (a[i] % a[j] == 0 && dp[j] + 1 > dp[i]) {
                dp[i] = dp[j] + 1;
                parent[i] = j;
            }
        }
        if (dp[i] > dp[best]) best = i;
    }

    vector<int> ans;
    while (best != -1) {
        ans.push_back(a[best]);
        best = parent[best];
    }
    reverse(ans.begin(), ans.end());
    for (int x : ans) cout << x << ' ';
    return 0;
}
