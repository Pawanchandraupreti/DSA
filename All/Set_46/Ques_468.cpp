// Minimum Number of Refueling Stops

#include <bits/stdc++.h>
using namespace std;

int main() {
    int target, fuel, n;
    cin >> target >> fuel >> n;
    vector<pair<int, int>> stops(n);
    for (auto& [pos, gas] : stops) cin >> pos >> gas;

    priority_queue<int> pq;
    int used = 0, i = 0;
    while (fuel < target) {
        while (i < n && stops[i].first <= fuel) pq.push(stops[i++].second);
        if (pq.empty()) {
            cout << -1;
            return 0;
        }
        fuel += pq.top();
        pq.pop();
        used++;
    }
    cout << used;
    return 0;
}
