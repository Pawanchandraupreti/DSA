// Rotate Array

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n;
    vector<int> a(n);
    for (int &x : a) cin >> x;
    cin >> k;

    if (n > 0) {
        k %= n;
        reverse(a.begin(), a.end());
        reverse(a.begin(), a.begin() + k);
        reverse(a.begin() + k, a.end());
    }

    for (int x : a) cout << x << ' ';
    cout << '\n';
    return 0;
}
