// Trailing Zeroes in a Factorial

#include <bits/stdc++.h>
using namespace std;

int main() {
    long long n;
    cin >> n;
    long long ans = 0;
    while (n) {
        n /= 5;
        ans += n;
    }
    cout << ans << '\n';
    return 0;
}

