// Minimum Taps to Water Garden

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> ranges(m);
    for (auto &[left, right] : ranges) cin >> left >> right;
    sort(ranges.begin(), ranges.end());

    int covered = 0, index = 0, answer = 0;
    while (covered < n && index < m) {
        int next = covered;
        while (index < m && ranges[index].first <= covered) next = max(next, ranges[index++].second);
        if (next == covered) {
            cout << -1 << '\n';
            return 0;
        }
        covered = next;
        answer++;
    }
    cout << answer << '\n';
    return 0;
}
