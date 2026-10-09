// K Closest Points to Origin

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<pair<int, int>> points(n);
    for (auto &point : points) cin >> point.first >> point.second;
    sort(points.begin(), points.end(), [](auto &first, auto &second) {
        return first.first * first.first + first.second * first.second < second.first * second.first + second.second * second.second;
    });
    for (int i = 0; i < min(k, n); i++) cout << points[i].first << ' ' << points[i].second << '\n';
    return 0;
}

