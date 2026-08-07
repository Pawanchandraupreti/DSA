// Count positive and negative numbers

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    if (!(cin >> n)) return 0;

    int pos = 0, neg = 0;
    for (int i = 0; i < n; ++i) {
        long long x;
        cin >> x;
        if (x > 0) ++pos;
        else if (x < 0) ++neg;
    }

    cout << pos << ' ' << neg;
    return 0;
}
