// Minimum Cost to Equalize Array

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<long long> a(n);
    for (long long &x : a) cin >> x;
    sort(a.begin(), a.end());
    long long median = a[n / 2], answer = 0;
    for (long long x : a) answer += abs(x - median);
    cout << answer << '\n';
    return 0;
}
