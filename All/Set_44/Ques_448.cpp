// 0/1 Knapsack

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, capacity;
    cin >> n >> capacity;
    vector<int> dp(capacity + 1);

    for (int i = 0; i < n; i++) {
        int weight, value;
        cin >> weight >> value;
        for (int j = capacity; j >= weight; j--) {
            dp[j] = max(dp[j], dp[j - weight] + value);
        }
    }

    cout << dp[capacity];
    return 0;
}
