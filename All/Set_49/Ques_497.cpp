// Best Time to Buy and Sell Stock

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> prices(n);
    for (int &x : prices) cin >> x;

    int minPrice = INT_MAX, maxProfit = 0;
    for (int x : prices) {
        minPrice = min(minPrice, x);
        maxProfit = max(maxProfit, x - minPrice);
    }

    cout << maxProfit << '\n';
    return 0;
}

