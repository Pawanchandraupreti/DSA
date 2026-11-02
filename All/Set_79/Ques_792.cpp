// Maximum Frequency After Increments

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    long long operations;
    cin >> n >> operations;
    vector<int> a(n);
    for (int &x : a) cin >> x;
    sort(a.begin(), a.end());
    long long sum = 0;
    int left = 0, answer = 0;
    for (int right = 0; right < n; right++) {
        sum += a[right];
        while (1LL * a[right] * (right - left + 1) - sum > operations) sum -= a[left++];
        answer = max(answer, right - left + 1);
    }
    cout << answer << '\n';
    return 0;
}
