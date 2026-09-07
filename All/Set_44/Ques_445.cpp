// House Robber II

#include <bits/stdc++.h>
using namespace std;

long long rob(vector<int>& a, int l, int r) {
    long long prev = 0, curr = 0;
    for (int i = l; i <= r; i++) {
        long long next = max(curr, prev + a[i]);
        prev = curr;
        curr = next;
    }
    return curr;
}

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int& x : a) cin >> x;

    if (n == 1) cout << a[0];
    else cout << max(rob(a, 0, n - 2), rob(a, 1, n - 1));
    return 0;
}
