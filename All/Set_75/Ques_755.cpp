// Minimum Removals for Mountain Array

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n), left(n, 1), right(n, 1);
    for (int &x : a) cin >> x;
    for (int i = 0; i < n; i++) for (int j = 0; j < i; j++) if (a[j] < a[i]) left[i] = max(left[i], left[j] + 1);
    for (int i = n - 1; i >= 0; i--) for (int j = n - 1; j > i; j--) if (a[j] < a[i]) right[i] = max(right[i], right[j] + 1);
    int longest = 0;
    for (int i = 1; i + 1 < n; i++) if (left[i] > 1 && right[i] > 1) longest = max(longest, left[i] + right[i] - 1);
    cout << n - longest << '\n';
    return 0;
}
