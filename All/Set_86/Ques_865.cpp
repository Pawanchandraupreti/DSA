// Count Subarrays with Fixed Bounds

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, low, high;
    cin >> n >> low >> high;
    long long answer = 0;
    int lastInvalid = -1, lastLow = -1, lastHigh = -1;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if (x < low || x > high) lastInvalid = i;
        if (x == low) lastLow = i;
        if (x == high) lastHigh = i;
        answer += max(0, min(lastLow, lastHigh) - lastInvalid);
    }
    cout << answer << '\n';
    return 0;
}
