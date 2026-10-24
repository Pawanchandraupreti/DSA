// Subarray Sum Divisible by K

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<long long> count(k);
    count[0] = 1;
    long long prefix = 0, answer = 0;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        prefix = (prefix + x) % k;
        if (prefix < 0) prefix += k;
        answer += count[prefix];
        count[prefix]++;
    }
    cout << answer << '\n';
    return 0;
}
