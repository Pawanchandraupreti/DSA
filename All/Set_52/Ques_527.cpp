// Activity Selection

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<pair<int, int>> activities(n);
    for (auto &[start, finish] : activities) cin >> start >> finish;
    sort(activities.begin(), activities.end(), [](auto &a, auto &b) {
        return a.second < b.second;
    });

    int answer = 0, lastFinish = INT_MIN;
    for (auto [start, finish] : activities) {
        if (start >= lastFinish) {
            answer++;
            lastFinish = finish;
        }
    }

    cout << answer << '\n';
    return 0;
}
