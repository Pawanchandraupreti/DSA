// Convex Hull Trick Dynamic Programming

#include <bits/stdc++.h>
using namespace std;

struct Line {
    long long slope, intercept;
    long long value(long long x) const { return slope * x + intercept; }
};

bool unnecessary(const Line &a, const Line &b, const Line &c) {
    return (__int128)(b.intercept - a.intercept) * (b.slope - c.slope)
         >= (__int128)(c.intercept - b.intercept) * (a.slope - b.slope);
}

int main() {
    int n;
    cin >> n;
    vector<long long> height(n), cost(n);
    for (long long &x : height) cin >> x;
    deque<Line> hull;
    hull.push_back({-2 * height[0], height[0] * height[0]});
    cost[0] = 0;
    for (int i = 1; i < n; i++) {
        while (hull.size() > 1 && hull[0].value(height[i]) >= hull[1].value(height[i]))
            hull.pop_front();
        cost[i] = height[i] * height[i] + hull.front().value(height[i]);
        Line next = {-2 * height[i], cost[i] + height[i] * height[i]};
        while (hull.size() > 1 && unnecessary(hull[hull.size() - 2], hull.back(), next))
            hull.pop_back();
        hull.push_back(next);
    }
    cout << cost.back() << '\n';
    return 0;
}
