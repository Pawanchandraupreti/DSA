// Merge Overlapping Intervals

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<pair<int, int>> intervals(n);
    for (auto &[start, end] : intervals) cin >> start >> end;
    sort(intervals.begin(), intervals.end());

    vector<pair<int, int>> merged;
    for (auto interval : intervals) {
        if (merged.empty() || merged.back().second < interval.first) merged.push_back(interval);
        else merged.back().second = max(merged.back().second, interval.second);
    }

    for (auto [start, end] : merged) cout << start << ' ' << end << '\n';
    return 0;
}


