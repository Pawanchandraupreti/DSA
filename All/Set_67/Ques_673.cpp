// Gas Station Circuit

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> gas(n), cost(n);
    for (int &x : gas) cin >> x;
    for (int &x : cost) cin >> x;

    int total = 0, tank = 0, start = 0;
    for (int i = 0; i < n; i++) {
        int difference = gas[i] - cost[i];
        total += difference;
        tank += difference;
        if (tank < 0) {
            tank = 0;
            start = i + 1;
        }
    }
    cout << (total >= 0 ? start : -1) << '\n';
    return 0;
}
