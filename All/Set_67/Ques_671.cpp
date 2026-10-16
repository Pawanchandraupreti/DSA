// Maximum Product Subarray

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    int currentMax, currentMin, answer;
    cin >> currentMax;
    currentMin = answer = currentMax;
    for (int i = 1; i < n; i++) {
        int x;
        cin >> x;
        if (x < 0) swap(currentMax, currentMin);
        currentMax = max(x, currentMax * x);
        currentMin = min(x, currentMin * x);
        answer = max(answer, currentMax);
    }
    cout << answer << '\n';
    return 0;
}
