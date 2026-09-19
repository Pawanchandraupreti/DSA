// Trapping Rain Water

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &x : a) cin >> x;

    int l = 0, r = n - 1, leftMax = 0, rightMax = 0, ans = 0;
    while (l <= r) {
        if (a[l] <= a[r]) {
            leftMax = max(leftMax, a[l]);
            ans += leftMax - a[l++];
        } else {
            rightMax = max(rightMax, a[r]);
            ans += rightMax - a[r--];
        }
    }

    cout << ans << '\n';
    return 0;
}


