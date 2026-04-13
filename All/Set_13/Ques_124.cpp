// Strongly Connected Components (Kosaraju's Algorithm)

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

void dfs1(int u, vector<vector<int>>& g, vector<int>& vis, stack<int>& st) {
    vis[u] = 1;
    for(int v : g[u]) {
        if(!vis[v]) dfs1(v, g, vis, st);
    }
    st.push(u);
}

void dfs2(int u, vector<vector<int>>& rg, vector<int>& vis) {
    vis[u] = 1;
    for(int v : rg[u]) {
        if(!vis[v]) dfs2(v, rg, vis);
    }
}

int main() {
    int n = 5;
    vector<vector<int>> g(n), rg(n);

    vector<pair<int,int>> edges = {
        {0,2}, {2,1}, {1,0}, {0,3}, {3,4}
    };

    for(auto e : edges) {
        g[e.first].push_back(e.second);
        rg[e.second].push_back(e.first);
    }

    vector<int> vis(n, 0);
    stack<int> st;

    for(int i = 0; i < n; i++) {
        if(!vis[i]) dfs1(i, g, vis, st);
    }

    fill(vis.begin(), vis.end(), 0);

    int sccCount = 0;
    while(!st.empty()) {
        int node = st.top();
        st.pop();

        if(!vis[node]) {
            sccCount++;
            dfs2(node, rg, vis);
        }
    }

    cout << sccCount;
}


