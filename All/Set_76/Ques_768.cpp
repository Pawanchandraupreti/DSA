// Stock Profit with At Most Three Transactions

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> price(n);
    for (int &x : price) cin >> x;
    vector<int> buy(4, INT_MIN), sell(4);
    for (int value : price) {
        for (int transaction = 1; transaction <= 3; transaction++) {
            buy[transaction] = max(buy[transaction], sell[transaction - 1] - value);
            sell[transaction] = max(sell[transaction], buy[transaction] + value);
        }
    }
    cout << sell[3] << '\n';
    return 0;
}
