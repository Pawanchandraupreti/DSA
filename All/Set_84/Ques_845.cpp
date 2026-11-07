// Maximum Events Attended

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<pair<int, int>> events(n);
    for (auto &[start, end] : events) cin >> start >> end;
    sort(events.begin(), events.end());
    priority_queue<int, vector<int>, greater<int>> heap;
    int day = 0, index = 0, answer = 0;
    while (index < n || !heap.empty()) {
        if (heap.empty()) day = max(day, events[index].first);
        while (index < n && events[index].first <= day) heap.push(events[index++].second);
        while (!heap.empty() && heap.top() < day) heap.pop();
        if (!heap.empty()) heap.pop(), answer++, day++;
    }
    cout << answer << '\n';
    return 0;
}
