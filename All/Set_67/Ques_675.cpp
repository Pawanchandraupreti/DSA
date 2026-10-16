// Maximum Sum Circular Subarray

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    int total = 0, currentMax = 0, currentMin = 0;
    int bestMax = INT_MIN, bestMin = INT_MAX;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        total += x;
        currentMax = max(x, currentMax + x);
        bestMax = max(bestMax, currentMax);
        currentMin = min(x, currentMin + x);
        bestMin = min(bestMin, currentMin);
    }
    cout << (bestMax < 0 ? bestMax : max(bestMax, total - bestMin)) << '\n';
    return 0;
}
