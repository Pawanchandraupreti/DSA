// Count Subarrays with Exactly K Odd Numbers

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    unordered_map<int, int> count;
    count[0] = 1;
    int odds = 0;
    long long answer = 0;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        odds += x % 2;
        answer += count[odds - k];
        count[odds]++;
    }
    cout << answer << '\n';
    return 0;
}
