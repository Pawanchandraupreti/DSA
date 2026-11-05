// Smallest Team Covering Skills

#include <bits/stdc++.h>
using namespace std;

int main() {
    int skills, people;
    cin >> skills >> people;
    vector<int> masks(people);
    for (int i = 0; i < people; i++) {
        int count, mask = 0;
        cin >> count;
        while (count--) { int skill; cin >> skill; mask |= 1 << skill; }
        masks[i] = mask;
    }
    vector<int> dp(1 << skills, people + 1);
    dp[0] = 0;
    for (int mask : masks) for (int current = 0; current < (1 << skills); current++) if (dp[current] <= people) dp[current | mask] = min(dp[current | mask], dp[current] + 1);
    cout << dp.back() << '\n';
    return 0;
}
