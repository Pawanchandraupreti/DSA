// Stock Profit with Transaction Fee

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, fee;
    cin >> n >> fee;
    vector<int> price(n);
    for (int &x : price) cin >> x;
    int cash = 0, hold = -price[0];
    for (int i = 1; i < n; i++) {
        int oldCash = cash;
        cash = max(cash, hold + price[i] - fee);
        hold = max(hold, oldCash - price[i]);
    }
    cout << cash << '\n';
    return 0;
}
