// Cheapest Flight Within K Stops

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m, source, destination, stops;
    cin >> n >> m >> source >> destination >> stops;
    vector<tuple<int, int, int>> flights(m);
    for (auto &[from, to, price] : flights) cin >> from >> to >> price;

    const int inf = 1e9;
    vector<int> cost(n, inf);
    cost[source] = 0;
    for (int step = 0; step <= stops; step++) {
        vector<int> next = cost;
        for (auto [from, to, price] : flights) if (cost[from] != inf) next[to] = min(next[to], cost[from] + price);
        cost = next;
    }
    cout << (cost[destination] == inf ? -1 : cost[destination]) << '\n';
    return 0;
}
