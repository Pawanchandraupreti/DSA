// Palindrome Linked List

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int& x : a) cin >> x;

    bool ok = true;
    for (int i = 0; i < n / 2; i++) {
        if (a[i] != a[n - 1 - i]) ok = false;
    }
    cout << (ok ? "true" : "false");
    return 0;
}
