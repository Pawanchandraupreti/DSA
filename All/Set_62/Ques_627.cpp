// Find Peak Element

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &x : a) cin >> x;

    for (int i = 0; i < n; i++) {
        bool left = (i == 0) || (a[i] >= a[i - 1]);
        bool right = (i == n - 1) || (a[i] >= a[i + 1]);
        if (left && right) {
            cout << i << '\n';
            return 0;
        }
    }
    cout << -1 << '\n';
    return 0;
}
