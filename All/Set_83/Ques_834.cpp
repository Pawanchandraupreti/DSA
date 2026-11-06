// Minimum Operations to Make Array Continuous

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &x : a) cin >> x;
    sort(a.begin(), a.end());
    a.erase(unique(a.begin(), a.end()), a.end());
    int best = 0, right = 0;
    for (int left = 0; left < (int)a.size(); left++) {
        while (right < (int)a.size() && a[right] < a[left] + n) right++;
        best = max(best, right - left);
    }
    cout << n - best << '\n';
    return 0;
}
