// Minimum Taps to Water Garden

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> reach(n + 1);
    for (int i = 0; i <= n; i++) {
        int range;
        cin >> range;
        reach[max(0, i - range)] = max(reach[max(0, i - range)], min(n, i + range));
    }
    int taps = 0, current = 0, farthest = 0;
    for (int i = 0; i < n; i++) {
        farthest = max(farthest, reach[i]);
        if (i == current) {
            taps++;
            current = farthest;
        }
        if (current <= i) {
            cout << -1 << '\n';
            return 0;
        }
    }
    cout << taps << '\n';
    return 0;
}
