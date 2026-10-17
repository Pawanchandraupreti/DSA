// Bellman Ford Shortest Paths

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m, source;
    cin >> n >> m >> source;
    vector<tuple<int, int, int>> edges(m);
    for (auto &[from, to, weight] : edges) cin >> from >> to >> weight;

    const int inf = 1e9;
    vector<int> distance(n, inf);
    distance[source] = 0;
    for (int i = 1; i < n; i++) {
        bool changed = false;
        for (auto [from, to, weight] : edges) {
            if (distance[from] != inf && distance[to] > distance[from] + weight) {
                distance[to] = distance[from] + weight;
                changed = true;
            }
        }
        if (!changed) break;
    }
    for (int value : distance) cout << (value == inf ? -1 : value) << ' ';
    cout << '\n';
    return 0;
}
