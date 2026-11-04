// Longest Subarray with K Distinct Values

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int &x : a) cin >> x;
    unordered_map<int, int> count;
    int left = 0, answer = 0;
    for (int right = 0; right < n; right++) {
        count[a[right]]++;
        while ((int)count.size() > k) if (--count[a[left++]] == 0) count.erase(a[left - 1]);
        answer = max(answer, right - left + 1);
    }
    cout << answer << '\n';
    return 0;
}
