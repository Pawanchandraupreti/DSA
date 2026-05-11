// Merge Overlapping Intervals

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    vector<pair<int, int>> intervals = {{1, 3}, {2, 6}, {8, 10}, {15, 18}};
    vector<pair<int, int>> merged;

    sort(intervals.begin(), intervals.end());

    for (const auto &interval : intervals) {
        if (merged.empty() || merged.back().second < interval.first) {
            merged.push_back(interval);
        } else {
            merged.back().second = max(merged.back().second, interval.second);
        }
    }

    cout << "Merged intervals: ";
    for (const auto &interval : merged) {
        cout << "[" << interval.first << ", " << interval.second << "] ";
    }
    cout << endl;

    return 0;
}
