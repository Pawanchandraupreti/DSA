// Merge overlapping intervals

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    if (!(cin >> n)) return 0;

    vector<pair<int, int>> intervals(n);
    for (int i = 0; i < n; ++i) {
        cin >> intervals[i].first >> intervals[i].second;
    }

    sort(intervals.begin(), intervals.end());


    
    vector<pair<int, int>> merged;
    for (const auto &interval : intervals) {
        if (merged.empty() || interval.first > merged.back().second) {
            merged.push_back(interval);
        } else {
            merged.back().second = max(merged.back().second, interval.second);
        }
    }

    cout << merged.size();
    for (const auto &interval : merged) {
        cout << '\n' << interval.first << ' ' << interval.second;
    }
    return 0;
}


