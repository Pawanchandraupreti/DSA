// Sort an Array of Zeroes, Ones and Twos

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &x : a) cin >> x;

    int l = 0, i = 0, r = n - 1;
    while (i <= r) {
        if (a[i] == 0) swap(a[i++], a[l++]);
        else if (a[i] == 2) swap(a[i], a[r--]);
        else i++;
    }
    for (int x : a) cout << x << ' ';
    cout << '\n';
    return 0;
}
