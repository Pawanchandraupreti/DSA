// Find the smallest element in an array

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    if (!(cin >> n)) return 0;

    long long mn = LLONG_MAX;
    for (int i = 0; i < n; ++i) {
        long long x;
        cin >> x;
        mn = min(mn, x);
    }

    cout << mn;
    return 0;
}
