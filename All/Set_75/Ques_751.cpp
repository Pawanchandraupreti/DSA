// Stock Profit with At Most K Transactions

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> price(n), buy(k + 1, INT_MIN), sell(k + 1);
    for (int &x : price) cin >> x;
    for (int value : price) {
        for (int transaction = 1; transaction <= k; transaction++) {
            buy[transaction] = max(buy[transaction], sell[transaction - 1] - value);
            sell[transaction] = max(sell[transaction], buy[transaction] + value);
        }
    }
    cout << sell[k] << '\n';
    return 0;
}
