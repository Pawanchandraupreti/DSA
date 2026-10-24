// Maximum Average Subarray

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int &x : a) cin >> x;
    long long sum = accumulate(a.begin(), a.begin() + k, 0LL), best = sum;
    for (int i = k; i < n; i++) {
        sum += a[i] - a[i - k];
        best = max(best, sum);
    }
    cout << fixed << setprecision(5) << (double)best / k << '\n';
    return 0;
}
