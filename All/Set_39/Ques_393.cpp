// Minimum Cost to Connect All Points

#include <bits/stdc++.h>
using namespace std;

long long minCostConnectPoints(const vector<pair<int, int>>& points) {
    int pointCount = (int)points.size();
    vector<int> minimumDistance(pointCount, INT_MAX);
    vector<bool> connected(pointCount, false);
    long long totalCost = 0;
    minimumDistance[0] = 0;

    for (int step = 0; step < pointCount; ++step) {
        int nextPoint = -1;
        for (int point = 0; point < pointCount; ++point) {
            if (!connected[point] && (nextPoint == -1 || minimumDistance[point] < minimumDistance[nextPoint])) {
                nextPoint = point;
            }
        }

        connected[nextPoint] = true;
        totalCost += minimumDistance[nextPoint];

        for (int point = 0; point < pointCount; ++point) {
            if (!connected[point]) {
                int distance = abs(points[nextPoint].first - points[point].first) +
                               abs(points[nextPoint].second - points[point].second);
                minimumDistance[point] = min(minimumDistance[point], distance);
            }
        }
    }

    return totalCost;
}

int main() {
    int n;
    cin >> n;

    vector<pair<int, int>> points(n);
    for (auto& [x, y] : points) cin >> x >> y;

    cout << minCostConnectPoints(points);
    return 0;
}
