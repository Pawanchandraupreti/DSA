// Kth Largest Subarray Sum

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int &x : a) cin >> x;
    vector<long long> sums;
    for (int i = 0; i < n; i++) {
        long long sum = 0;
        for (int j = i; j < n; j++) sum += a[j], sums.push_back(sum);
    }
    nth_element(sums.begin(), sums.end() - k, sums.end());
    cout << sums[sums.size() - k] << '\n';
    return 0;
}
