// Minimum Operations to Reduce X to Zero

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    long long total = 0;
    for (int &value : a) { cin >> value; total += value; }
    long long target = total - x, sum = 0;
    int left = 0, longest = target == 0 ? 0 : -1;
    for (int right = 0; right < n; right++) {
        sum += a[right];
        while (sum > target) sum -= a[left++];
        if (sum == target) longest = max(longest, right - left + 1);
    }
    cout << (longest == -1 ? -1 : n - longest) << '\n';
    return 0;
}
