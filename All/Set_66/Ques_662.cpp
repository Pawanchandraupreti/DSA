// Minimum Size Subarray Sum

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, target;
    cin >> n >> target;
    vector<int> a(n);
    for (int &x : a) cin >> x;

    int left = 0, sum = 0, answer = n + 1;
    for (int right = 0; right < n; right++) {
        sum += a[right];
        while (sum >= target) {
            answer = min(answer, right - left + 1);
            sum -= a[left++];
        }
    }
    cout << (answer == n + 1 ? 0 : answer) << '\n';
    return 0;
}
