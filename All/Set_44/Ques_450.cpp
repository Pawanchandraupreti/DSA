// Trapping Rain Water

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> h(n);
    for (int& x : h) cin >> x;

    int l = 0, r = n - 1, leftMax = 0, rightMax = 0, ans = 0;
    while (l < r) {
        if (h[l] <= h[r]) {
            leftMax = max(leftMax, h[l]);
            ans += leftMax - h[l++];
        } else {
            rightMax = max(rightMax, h[r]);
            ans += rightMax - h[r--];
        }
    }

    cout << ans;
    return 0;
}
