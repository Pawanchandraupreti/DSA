// Find the maximum number of activities that do not overlap

#include <bits/stdc++.h>
using namespace std;

int maximumActivities(vector<pair<int, int>> activities) {
    sort(activities.begin(), activities.end(), [](const auto& first, const auto& second) {
        return first.second < second.second;
    });

    int count = 0;
    int lastFinish = INT_MIN;

    for (const auto& activity : activities) {
        if (activity.first >= lastFinish) {
            ++count;
            lastFinish = activity.second;
        }
    }

    return count;
}

int main() {
    int n;
    cin >> n;

    vector<pair<int, int>> activities(n);
    for (auto& activity : activities) {
        cin >> activity.first >> activity.second;
    }

    cout << maximumActivities(activities);
    return 0;
}


