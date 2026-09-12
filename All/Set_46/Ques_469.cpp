// Subarray Sum Equals K

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    unordered_map<int, int> cnt;
    cnt[0] = 1;
    int sum = 0, ans = 0;

    while (n--) {
        int x;
        cin >> x;
        sum += x;
        ans += cnt[sum - k];
        cnt[sum]++;
    }
    cout << ans;
    return 0;
}
