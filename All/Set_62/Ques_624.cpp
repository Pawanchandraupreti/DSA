// Remove Duplicates from Sorted Array

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &x : a) cin >> x;

    int k = 1;
    for (int i = 1; i < n; i++) {
        if (a[i] != a[k - 1]) a[k++] = a[i];
    }

    cout << k << '\n';
    for (int i = 0; i < k; i++) cout << a[i] << ' ';
    cout << '\n';
    return 0;
}
