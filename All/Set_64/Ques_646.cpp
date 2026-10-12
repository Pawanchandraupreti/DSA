// Kth Largest Element

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int &x : a) cin >> x;

    nth_element(a.begin(), a.end() - k, a.end());
    cout << a[n - k] << '\n';
    return 0;
}
