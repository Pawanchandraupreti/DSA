// Maximum Points from Cards

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int &x : a) cin >> x;
    long long total = accumulate(a.begin(), a.end(), 0LL), window = 0;
    for (int i = 0; i < n - k; i++) window += a[i];
    long long smallest = window;
    for (int i = n - k; i < n; i++) {
        window += a[i];
        if (i >= n - k) window -= a[i - (n - k)];
        smallest = min(smallest, window);
    }
    cout << total - smallest << '\n';
    return 0;
}
