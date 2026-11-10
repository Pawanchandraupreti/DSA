// Minimum Cost to Buy Candies

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> price(n);
    for (int &x : price) cin >> x;
    sort(price.rbegin(), price.rend());
    int answer = 0;
    for (int i = 0; i < n; i++) if (i % 3 != 2) answer += price[i];
    cout << answer << '\n';
    return 0;
}

