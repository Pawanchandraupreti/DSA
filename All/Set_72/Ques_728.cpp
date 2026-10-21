// Network Delay Time

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m, source;
    cin >> n >> m >> source;
    vector<vector<pair<int, int>>> graph(n);
    for (int i = 0; i < m; i++) {
        int from, to, weight;
        cin >> from >> to >> weight;
        graph[from].push_back({to, weight});
    }

    const int inf = 1e9;
    vector<int> distance(n, inf);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> heap;
    distance[source] = 0;
    heap.push({0, source});
    while (!heap.empty()) {
        auto [time, node] = heap.top();
        heap.pop();
        if (time != distance[node]) continue;
        for (auto [next, weight] : graph[node]) if (distance[next] > time + weight) {
            distance[next] = time + weight;
            heap.push({distance[next], next});
        }
    }
    int answer = *max_element(distance.begin(), distance.end());
    cout << (answer == inf ? -1 : answer) << '\n';
    return 0;
}
