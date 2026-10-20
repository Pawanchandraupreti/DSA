// Minimum Cost Climbing Stairs

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> cost(n);
    for (int &x : cost) cin >> x;
    int previousTwo = 0, previousOne = 0;
    for (int i = 2; i <= n; i++) {
        int current = min(previousOne + cost[i - 1], previousTwo + cost[i - 2]);
        previousTwo = previousOne;
        previousOne = current;
    }
    cout << previousOne << '\n';
    return 0;
}


