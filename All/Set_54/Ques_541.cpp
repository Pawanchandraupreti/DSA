// Find Peak Element

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &x : a) cin >> x;

    int left = 0, right = n - 1;
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (a[mid] > a[mid + 1]) right = mid;
        else left = mid + 1;
    }

    cout << left << '\n';
    return 0;
}
