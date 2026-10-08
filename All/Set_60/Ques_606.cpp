// Gas Station

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> gas(n), cost(n);
    for (int &value : gas) cin >> value;
    for (int &value : cost) cin >> value;
    int total = 0, current = 0, start = 0;
    for (int i = 0; i < n; i++) {
        total += gas[i] - cost[i];
        current += gas[i] - cost[i];
        if (current < 0) {
            current = 0;
            start = i + 1;
        }
    }
    cout << (total >= 0 ? start : -1) << '\n';
    return 0;
}


