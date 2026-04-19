// Dijkstra's Shortest Path Algorithm
// Time Complexity: O((V + E) log V)

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

vector<int> dijkstra(int n, int src, vector<vector<pair<int, int>>>& g) {
    const int INF = 1000000000;
    vector<int> dist(n, INF);
    dist[src] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, src});

    while(!pq.empty()) {
        int d = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        if(d != dist[u]) continue;

        for(auto edge : g[u]) {
            int v = edge.first;
            int w = edge.second;
            if(dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }

    return dist;
}

int main() {
    int n = 5;
    vector<vector<pair<int, int>>> g(n);

    g[0].push_back({1, 10});
    g[0].push_back({4, 5});
    g[1].push_back({2, 1});
    g[1].push_back({4, 2});
    g[2].push_back({3, 4});
    g[3].push_back({0, 7});
    g[3].push_back({2, 6});
    g[4].push_back({1, 3});
    g[4].push_back({2, 9});
    g[4].push_back({3, 2});

    vector<int> dist = dijkstra(n, 0, g);
    for(int d : dist) cout << d << " ";
}



