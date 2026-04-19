// Binary Lifting - Kth Ancestor Query


#include <iostream>
#include <vector>
using namespace std;

void dfs(int u, int p, vector<vector<int>>& g, vector<vector<int>>& up, int LOG) {
    up[u][0] = p;

    for(int j = 1; j < LOG; j++) {
        if(up[u][j - 1] == -1) up[u][j] = -1;
        else up[u][j] = up[up[u][j - 1]][j - 1];
    }

    for(int v : g[u]) {
        if(v != p) dfs(v, u, g, up, LOG);
    }
}

int kthAncestor(int node, int k, vector<vector<int>>& up, int LOG) {
    for(int j = 0; j < LOG; j++) {
        if(node == -1) break;
        if(k & (1 << j)) node = up[node][j];
    }
    return node;
}

int main() {
    int n = 7;
    vector<vector<int>> g(n);

    vector<pair<int, int>> edges = {
        {0,1}, {0,2}, {1,3}, {1,4}, {2,5}, {2,6}
    };

    for(auto e : edges) {
        g[e.first].push_back(e.second);
        g[e.second].push_back(e.first);
    }

    int LOG = 0;
    while((1 << LOG) <= n) LOG++;
    vector<vector<int>> up(n, vector<int>(LOG, -1));

    dfs(0, -1, g, up, LOG);

    cout << kthAncestor(4, 1, up, LOG) << "\n";
    cout << kthAncestor(4, 2, up, LOG);
}
