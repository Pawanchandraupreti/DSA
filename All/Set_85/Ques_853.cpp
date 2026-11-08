// Count Nice Pairs

#include <bits/stdc++.h>
using namespace std;

int reverseNumber(int value) {
    int result = 0;
    while (value) result = result * 10 + value % 10, value /= 10;
    return result;
}

int main() {
    int n;
    cin >> n;
    const long long mod = 1000000007;
    unordered_map<int, long long> count;
    long long answer = 0;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        int key = x - reverseNumber(x);
        answer = (answer + count[key]) % mod;
        count[key]++;
    }
    cout << answer << '\n';
    return 0;
}
