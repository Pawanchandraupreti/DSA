// Maximum Value of Equation

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, limit;
    cin >> n >> limit;
    vector<pair<int, int>> points(n);
    for (auto &[x, y] : points) cin >> x >> y;
    deque<pair<int, int>> q;
    long long answer = LLONG_MIN;
    for (auto [x, y] : points) {
        while (!q.empty() && x - q.front().second > limit) q.pop_front();
        if (!q.empty()) answer = max(answer, 1LL * x + y + q.front().first);
        while (!q.empty() && q.back().first <= y - x) q.pop_back();
        q.push_back({y - x, x});
    }
    cout << answer << '\n';
    return 0;
}
