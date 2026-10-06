// Min Cost Climbing Stairs

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> cost(n);
    for (int &value : cost) cin >> value;
    int oneStep = 0, twoSteps = 0;
    for (int i = 2; i <= n; i++) {
        int current = min(oneStep + cost[i - 1], twoSteps + cost[i - 2]);
        twoSteps = oneStep;
        oneStep = current;
    }
    cout << oneStep << '\n';
    return 0;
}


