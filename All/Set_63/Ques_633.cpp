// Move Zeroes to End

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &x : a) cin >> x;

    int position = 0;
    for (int x : a) {
        if (x != 0) a[position++] = x;
    }
    while (position < n) a[position++] = 0;

    for (int x : a) cout << x << ' ';
    cout << '\n';
    return 0;
}
