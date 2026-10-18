// Stock Profit with Cooldown

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> price(n);
    for (int &x : price) cin >> x;
    int hold = -price[0], sold = 0, cooldown = 0;
    for (int i = 1; i < n; i++) {
        int oldHold = hold, oldSold = sold;
        hold = max(hold, cooldown - price[i]);
        sold = oldHold + price[i];
        cooldown = max(cooldown, oldSold);
    }
    cout << max(sold, cooldown) << '\n';
    return 0;
}
