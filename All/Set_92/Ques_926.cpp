// Number of Ways to Climb Stairs

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    const long long mod = 1000000007;
    long long a = 1, b = 1;
    for (int i = 2; i <= n; i++) {
        long long c = (a + b) % mod;
        a = b;
        b = c;
    }
    cout << b << '\n';
    return 0;
}
