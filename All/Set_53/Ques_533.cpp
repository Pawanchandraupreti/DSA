// Non-overlapping Intervals

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<pair<int, int>> intervals(n);
    for (auto &[start, finish] : intervals) cin >> start >> finish;
    sort(intervals.begin(), intervals.end(), [](auto &a, auto &b) {
        return a.second < b.second;
    });

    int removed = 0, lastFinish = INT_MIN;
    for (auto [start, finish] : intervals) {
        if (start < lastFinish) removed++;
        else lastFinish = finish;
    }

    cout << removed << '\n';
    return 0;
}
