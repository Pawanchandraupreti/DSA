// Minimum Refueling Stops

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    long long target, fuel;
    cin >> target >> fuel >> n;
    vector<pair<int, int>> stations(n);
    for (auto &[position, amount] : stations) cin >> position >> amount;
    priority_queue<int> heap;
    long long distance = fuel;
    int stops = 0, index = 0;
    while (distance < target) {
        while (index < n && stations[index].first <= distance) heap.push(stations[index++].second);
        if (heap.empty()) {
            cout << -1 << '\n';
            return 0;
        }
        distance += heap.top();
        heap.pop();
        stops++;
    }
    cout << stops << '\n';
    return 0;
}
