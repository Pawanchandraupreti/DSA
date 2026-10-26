// Partition Array into K Equal Sum Subsets

#include <bits/stdc++.h>
using namespace std;

bool solve(vector<int> &a, vector<bool> &used, int start, int groups, int current, int target) {
    if (groups == 1) return true;
    if (current == target) return solve(a, used, 0, groups - 1, 0, target);
    for (int i = start; i < (int)a.size(); i++) {
        if (!used[i] && current + a[i] <= target) {
            used[i] = true;
            if (solve(a, used, i + 1, groups, current + a[i], target)) return true;
            used[i] = false;
        }
    }
    return false;
}

int main() {
    int n, groups, total = 0;
    cin >> n >> groups;
    vector<int> a(n);
    for (int &x : a) { cin >> x; total += x; }
    if (total % groups) cout << "NO\n";
    else {
        sort(a.rbegin(), a.rend());
        vector<bool> used(n);
        cout << (solve(a, used, 0, groups, 0, total / groups) ? "YES" : "NO") << '\n';
    }
    return 0;
}
