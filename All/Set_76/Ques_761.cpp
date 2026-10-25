// Jump Game Minimum Jumps

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &x : a) cin >> x;
    int jumps = 0, currentEnd = 0, farthest = 0;
    for (int i = 0; i + 1 < n; i++) {
        farthest = max(farthest, i + a[i]);
        if (i == currentEnd) {
            jumps++;
            currentEnd = farthest;
        }
    }
    cout << jumps << '\n';
    return 0;
}
