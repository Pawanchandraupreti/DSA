// Max Flow (Edmonds-Karp Algorithm)
// Time Complexity: O(V * E^2)

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

bool bfs(int s, int t, vector<vector<int>>& cap, vector<vector<int>>& adj, vector<int>& parent) {
    fill(parent.begin(), parent.end(), -1);
    parent[s] = -2;

    queue<pair<int, int>> q;
    q.push({s, 1000000000});

    while(!q.empty()) {
        int u = q.front().first;
        int flow = q.front().second;
        q.pop();

        for(int v : adj[u]) {
            if(parent[v] == -1 && cap[u][v] > 0) {
                parent[v] = u;
                int newFlow = min(flow, cap[u][v]);

                if(v == t) {
                    return true;
                }

                q.push({v, newFlow});
            }
        }
    }

    return false;
}

int maxFlow(int n, int s, int t, vector<vector<int>>& cap, vector<vector<int>>& adj) {
    int flow = 0;
    vector<int> parent(n);

    while(bfs(s, t, cap, adj, parent)) {
        int newFlow = 1000000000;
        int cur = t;

        while(cur != s) {
            int prev = parent[cur];
            newFlow = min(newFlow, cap[prev][cur]);
            cur = prev;
        }

        cur = t;
        while(cur != s) {
            int prev = parent[cur];
            cap[prev][cur] -= newFlow;
            cap[cur][prev] += newFlow;
            cur = prev;
        }

        flow += newFlow;
    }

    return flow;
}

int main() {
    int n = 6, source = 0, sink = 5;
    vector<vector<int>> cap(n, vector<int>(n, 0));
    vector<vector<int>> adj(n);

    vector<vector<int>> edges = {
        {0,1,16}, {0,2,13}, {1,2,10}, {2,1,4},
        {1,3,12}, {3,2,9}, {2,4,14}, {4,3,7},
        {3,5,20}, {4,5,4}
    };

    for(auto& e : edges) {
        int u = e[0], v = e[1], c = e[2];
        cap[u][v] += c;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    cout << maxFlow(n, source, sink, cap, adj);
}
