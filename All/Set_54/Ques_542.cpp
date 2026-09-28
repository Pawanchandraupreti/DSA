// Missing Number

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &x : a) cin >> x;

    int xorAll = 0;
    for (int i = 0; i <= n; i++) xorAll ^= i;
    for (int x : a) xorAll ^= x;

    cout << xorAll << '\n';
    return 0;
}
