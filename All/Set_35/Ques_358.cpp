// Merge overlapping intervals

#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> mergeIntervals(vector<pair<int, int>> intervals) {
    if (intervals.empty()) return {};

    sort(intervals.begin(), intervals.end());
    vector<pair<int, int>> merged;
    merged.push_back(intervals[0]);

    for (int i = 1; i < (int)intervals.size(); ++i) {
        if (intervals[i].first <= merged.back().second) {
            merged.back().second = max(merged.back().second, intervals[i].second);
        } else {
            merged.push_back(intervals[i]);
        }
    }

    return merged;
}

int main() {
    int n;
    cin >> n;

    vector<pair<int, int>> intervals(n);
    for (int i = 0; i < n; ++i) {
        cin >> intervals[i].first >> intervals[i].second;
    }

    vector<pair<int, int>> result = mergeIntervals(intervals);
    for (const auto& interval : result) {
        cout << interval.first << ' ' << interval.second << '\n';
    }
    return 0;
}

