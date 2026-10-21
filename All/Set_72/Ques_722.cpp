// Wiggle Subsequence Length

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &x : a) cin >> x;
    if (n == 0) {
        cout << 0 << '\n';
        return 0;
    }

    int up = 1, down = 1;
    for (int i = 1; i < n; i++) {
        if (a[i] > a[i - 1]) up = down + 1;
        else if (a[i] < a[i - 1]) down = up + 1;
    }
    cout << max(up, down) << '\n';
    return 0;
}
