// Count Smaller Elements to the Right

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n), sorted;
    for (int &x : a) cin >> x;
    sorted = a;
    sort(sorted.begin(), sorted.end());
    vector<int> bit(n + 1), answer(n);
    auto update = [&](int index) { for (; index <= n; index += index & -index) bit[index]++; };
    auto query = [&](int index) { int result = 0; for (; index; index -= index & -index) result += bit[index]; return result; };
    for (int i = n - 1; i >= 0; i--) {
        int rank = lower_bound(sorted.begin(), sorted.end(), a[i]) - sorted.begin() + 1;
        answer[i] = query(rank - 1);
        update(rank);
    }
    for (int x : answer) cout << x << ' ';
    cout << '\n';
    return 0;
}

