// Two Sum

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, target;
    cin >> n;
    vector<int> a(n);
    for (int &x : a) cin >> x;
    cin >> target;

    unordered_map<int, int> seen;
    for (int i = 0; i < n; i++) {
        int need = target - a[i];
        if (seen.count(need)) {
            cout << seen[need] << ' ' << i << '\n';
            return 0;
        }
        seen[a[i]] = i;
    }

    cout << -1 << '\n';
    return 0;
}
