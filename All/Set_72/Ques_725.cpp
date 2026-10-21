// Minimum Palindrome Partition Cuts

#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    int n = s.size();
    vector<int> cuts(n);
    vector<vector<bool>> palindrome(n, vector<bool>(n));
    for (int right = 0; right < n; right++) {
        cuts[right] = right;
        for (int left = 0; left <= right; left++) {
            if (s[left] == s[right] && (right - left < 2 || palindrome[left + 1][right - 1])) {
                palindrome[left][right] = true;
                cuts[right] = left == 0 ? 0 : min(cuts[right], cuts[left - 1] + 1);
            }
        }
    }
    cout << (n ? cuts[n - 1] : 0) << '\n';
    return 0;
}
