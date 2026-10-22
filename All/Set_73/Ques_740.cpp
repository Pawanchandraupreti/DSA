// Minimum Cost Tickets

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> days(n), cost(3), dp(n + 1);
    for (int &day : days) cin >> day;
    for (int &value : cost) cin >> value;
    for (int i = 1; i <= n; i++) {
        dp[i] = dp[i - 1] + cost[0];
        int week = i - 1;
        while (week >= 0 && days[week] >= days[i - 1] - 6) week--;
        dp[i] = min(dp[i], dp[week + 1] + cost[1]);
        int month = i - 1;
        while (month >= 0 && days[month] >= days[i - 1] - 29) month--;
        dp[i] = min(dp[i], dp[month + 1] + cost[2]);
    }
    cout << dp[n] << '\n';
    return 0;
}
