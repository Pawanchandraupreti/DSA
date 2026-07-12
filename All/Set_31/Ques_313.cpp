// Find the missing number from 1 to n

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    if (!(cin >> n)) return 0;

    long long sum = 0;
    for (int i = 0; i < n - 1; ++i) {
        long long x;
        cin >> x;
        sum += x;
    }

    long long expected = 1LL * n * (n + 1) / 2;
    cout << expected - sum;
    return 0;
}

