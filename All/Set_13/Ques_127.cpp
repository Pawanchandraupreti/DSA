// Articulation Points in Graph (Tarjan's Algorithm)

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void dfs(int u, int parent, vector<vector<int>>& g, vector<int>& vis,
         vector<int>& tin, vector<int>& low, vector<int>& isArt, int& timer) {
    vis[u] = 1;
    tin[u] = low[u] = timer++;
    int children = 0;

    for(int v : g[u]) {
        if(v == parent) continue;

        if(vis[v]) {
            low[u] = min(low[u], tin[v]);
        }
        else {
            dfs(v, u, g, vis, tin, low, isArt, timer);
            low[u] = min(low[u], low[v]);

            if(low[v] >= tin[u] && parent != -1)
                isArt[u] = 1;

            children++;
        }
    }

    if(parent == -1 && children > 1)
        isArt[u] = 1;
}

int main() {
    int n = 5;
    vector<vector<int>> g(n);

    vector<pair<int,int>> edges = {
        {0,1}, {1,2}, {2,0}, {1,3}, {3,4}
    };

    for(auto e : edges) {
        g[e.first].push_back(e.second);
        g[e.second].push_back(e.first);
    }

    vector<int> vis(n, 0), tin(n, -1), low(n, -1), isArt(n, 0);
    int timer = 0;

    for(int i = 0; i < n; i++) {
        if(!vis[i]) dfs(i, -1, g, vis, tin, low, isArt, timer);
    }

    for(int i = 0; i < n; i++) {
        if(isArt[i]) cout << i << " ";
    }
}


