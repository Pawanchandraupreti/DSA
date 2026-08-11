// Count the number of subarrays with sum equal to k

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    long long k;
    if (!(cin >> n >> k)) return 0;

    unordered_map<long long, long long> freq;
    freq[0] = 1;

    long long sum = 0, count = 0;
    for (int i = 0; i < n; ++i) {
        long long x;
        cin >> x;
        sum += x;
        auto it = freq.find(sum - k);
        if (it != freq.end()) count += it->second;
        ++freq[sum];
    }

    cout << count;
    return 0;
}