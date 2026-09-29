// Best Time to Buy and Sell Stock

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    int lowest = INT_MAX, profit = 0;
    for (int i = 0; i < n; i++) {
        int price;
        cin >> price;
        lowest = min(lowest, price);
        profit = max(profit, price - lowest);
    }
    cout << profit << '\n';
    return 0;
}

