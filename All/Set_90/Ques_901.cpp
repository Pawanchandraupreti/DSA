// Rotate an Array to the Right

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int &x : a) cin >> x;
    if (n) {
        k %= n;
        rotate(a.begin(), a.end() - k, a.end());
    }
    for (int x : a) cout << x << ' ';
    cout << '\n';
    return 0;
}
