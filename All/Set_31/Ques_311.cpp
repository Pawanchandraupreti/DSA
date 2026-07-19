// Print all prime numbers up to n

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    if (!(cin >> n)) return 0;

    vector<bool> isPrime(n + 1, true);
    if (n >= 0) isPrime[0] = false;
    if (n >= 1) isPrime[1] = false;

    for (int i = 2; i * i <= n; ++i) {
        if (isPrime[i]) {
            for (int j = i * i; j <= n; j += i) {
                isPrime[j] = false;
            }
        }
    }

    bool first = true;
    for (int i = 2; i <= n; ++i) {
        if (isPrime[i]) {
            if (!first) cout << ' ';
            cout << i;
            first = false;
        }
    }
    return 0;
}


