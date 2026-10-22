// Minimum Cost to Connect Points

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<pair<int, int>> points(n);
    for (auto &[x, y] : points) cin >> x >> y;
    vector<int> distance(n, INT_MAX);
    vector<bool> used(n);
    distance[0] = 0;
    int answer = 0;
    for (int step = 0; step < n; step++) {
        int node = -1;
        for (int i = 0; i < n; i++) if (!used[i] && (node == -1 || distance[i] < distance[node])) node = i;
        used[node] = true;
        answer += distance[node];
        for (int i = 0; i < n; i++) if (!used[i]) distance[i] = min(distance[i], abs(points[node].first - points[i].first) + abs(points[node].second - points[i].second));
    }
    cout << answer << '\n';
    return 0;
}
