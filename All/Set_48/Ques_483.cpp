// Search in Rotated Sorted Array

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, target;
    cin >> n;
    vector<int> a(n);
    for (int &x : a) cin >> x;
    cin >> target;

    int l = 0, r = n - 1, ans = -1;
    while (l <= r) {
        int mid = l + (r - l) / 2;
        if (a[mid] == target) {
            ans = mid;
            break;
        }
        if (a[l] <= a[mid]) {
            if (a[l] <= target && target < a[mid]) r = mid - 1;
            else l = mid + 1;
        } else {
            if (a[mid] < target && target <= a[r]) l = mid + 1;
            else r = mid - 1;
        }
    }

    cout << ans << '\n';
    return 0;
}


