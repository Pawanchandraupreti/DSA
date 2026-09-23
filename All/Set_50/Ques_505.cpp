// First Missing Positive

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &x : a) cin >> x;

    for (int i = 0; i < n; i++) {
        while (a[i] >= 1 && a[i] <= n && a[a[i] - 1] != a[i]) {
            swap(a[i], a[a[i] - 1]);
        }
    }

    for (int i = 0; i < n; i++) {
        if (a[i] != i + 1) {
            cout << i + 1 << '\n';
            return 0;
        }
    }

    cout << n + 1 << '\n';
    return 0;
}
