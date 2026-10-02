// Maximum Subarray

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    int current = 0, best = INT_MIN;
    for (int i = 0; i < n; i++) {
        int value;
        cin >> value;
        current = max(value, current + value);
        best = max(best, current);
    }
    cout << best << '\n';
    return 0;
}

