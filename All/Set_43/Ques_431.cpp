// Biconnected Components

#include <bits/stdc++.h>
using namespace std;

vector<pair<int,int>> edges;
vector<vector<int>> graph;
vector<int> disc, low, parent;
vector<vector<pair<int,int>>> components;
stack<pair<int,int>> st;
int timer = 0;

void dfs(int u) {
    disc[u] = low[u] = timer++;
    int children = 0;
    
    for (int v : graph[u]) {
        if (disc[v] == -1) {
            children++;
            parent[v] = u;
            st.push({u, v});
            dfs(v);
            low[u] = min(low[u], low[v]);
            
            if ((parent[u] == -1 && children > 1) || (parent[u] != -1 && low[v] >= disc[u])) {
                vector<pair<int,int>> comp;
                pair<int,int> e;
                do {
                    e = st.top();
                    st.pop();
                    comp.push_back(e);
                } while (e != make_pair(u, v));
                components.push_back(comp);
            }
        } else if (v != parent[u] && disc[v] < disc[u]) {
            low[u] = min(low[u], disc[v]);
            st.push({u, v});
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    graph.resize(n);
    disc.assign(n, -1);
    low.assign(n, 0);
    parent.assign(n, -1);
    
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    
    for (int i = 0; i < n; i++) {
        if (disc[i] == -1) dfs(i);
    }
    
    cout << components.size();
    return 0;
}
