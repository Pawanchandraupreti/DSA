// Max Consecutive Ones with K Flips

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int &x : a) cin >> x;
    int left = 0, zeros = 0, answer = 0;
    for (int right = 0; right < n; right++) {
        zeros += a[right] == 0;
        while (zeros > k) {
            zeros -= a[left] == 0;
            left++;
        }
        answer = max(answer, right - left + 1);
    }
    cout << answer << '\n';
    return 0;
}
