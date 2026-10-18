// Kth Smallest Pair Distance

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int &x : a) cin >> x;
    sort(a.begin(), a.end());

    int left = 0, right = a.back() - a.front();
    while (left < right) {
        int middle = (left + right) / 2;
        long long count = 0;
        for (int i = 0, j = 0; i < n; i++) {
            while (j < n && a[j] - a[i] <= middle) j++;
            count += j - i - 1;
        }
        if (count >= k) right = middle;
        else left = middle + 1;
    }
    cout << left << '\n';
    return 0;
}
