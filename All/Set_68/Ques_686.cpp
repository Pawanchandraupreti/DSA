// Minimum Meeting Rooms

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<pair<int, int>> events;
    for (int i = 0; i < n; i++) {
        int start, end;
        cin >> start >> end;
        events.push_back({start, 1});
        events.push_back({end, -1});
    }
    sort(events.begin(), events.end(), [](auto first, auto second) {
        if (first.first != second.first) return first.first < second.first;
        return first.second < second.second;
    });

    int rooms = 0, answer = 0;
    for (auto [time, change] : events) {
        rooms += change;
        answer = max(answer, rooms);
    }
    cout << answer << '\n';
    return 0;
}
