// Evaluate Division

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    unordered_map<string, vector<pair<string, double>>> g;
    while (n--) {
        string a, b;
        double x;
        cin >> a >> b >> x;
        g[a].push_back({b, x});
        g[b].push_back({a, 1.0 / x});
    }

    int q;
    cin >> q;
    while (q--) {
        string s, t;
        cin >> s >> t;
        unordered_set<string> seen;
        queue<pair<string, double>> que;
        que.push({s, 1});
        double ans = -1;
        while (!que.empty()) {
            auto [u, val] = que.front();
            que.pop();
            if (u == t) {
                ans = val;
                break;
            }
            if (!seen.insert(u).second) continue;
            for (auto [v, w] : g[u]) que.push({v, val * w});
        }
        cout << ans << '\n';
    }
    return 0;
}
