// Count frequency of each element in an array

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    if (!(cin >> n)) return 0;

    unordered_map<long long, int> freq;
    vector<long long> order;

    for (int i = 0; i < n; ++i) {
        long long x;
        cin >> x;
        if (freq.find(x) == freq.end()) order.push_back(x);
        ++freq[x];
    }

    for (long long x : order) {
        cout << x << ' ' << freq[x] << '\n';
    }
    return 0;
}

