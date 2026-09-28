// Remove Duplicates from Sorted Array

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &x : a) cin >> x;

    int write = 1;
    for (int i = 1; i < n; i++) {
        if (a[i] != a[write - 1]) a[write++] = a[i];
    }

    for (int i = 0; i < write; i++) cout << a[i] << ' ';
    cout << '\n';
    return 0;
}
