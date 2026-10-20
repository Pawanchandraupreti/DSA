// House Robber in a Circle

#include <bits/stdc++.h>
using namespace std;

int rob(const vector<int> &a, int left, int right) {
    int previousTwo = 0, previousOne = 0;
    for (int i = left; i <= right; i++) {
        int current = max(previousOne, previousTwo + a[i]);
        previousTwo = previousOne;
        previousOne = current;
    }
    return previousOne;
}

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &x : a) cin >> x;
    if (n == 1) cout << a[0] << '\n';
    else cout << max(rob(a, 0, n - 2), rob(a, 1, n - 1)) << '\n';
    return 0;
}
