// Product Queries of Powers of Two

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, queries;
    cin >> n >> queries;
    vector<long long> powers;
    for (int bit = 0; (1 << bit) <= n; bit++) if (n & (1 << bit)) powers.push_back(1LL << bit);
    const long long mod = 1000000007;
    while (queries--) {
        int left, right;
        cin >> left >> right;
        long long answer = 1;
        for (int i = left; i <= right; i++) answer = answer * powers[i] % mod;
        cout << answer << '\n';
    }
    return 0;
}

