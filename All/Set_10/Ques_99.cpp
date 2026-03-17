// Detect Cycle in Directed Graph (DFS)

#include <iostream>
#include <vector>
using namespace std;

bool dfs(int node, vector<int> adj[], vector<int>& vis, vector<int>& pathVis) {

    vis[node] = 1;
    pathVis[node] = 1;

    for(auto it : adj[node]) {

        if(!vis[it]) {
            if(dfs(it, adj, vis, pathVis))
                return true;
        }
        else if(pathVis[it])
            return true;
    }

    pathVis[node] = 0;
    return false;
}

int main() {

    int V = 4;
    vector<int> adj[4];

    adj[0].push_back(1);
    adj[1].push_back(2);
    adj[2].push_back(3);
    adj[3].push_back(1); // cycle

    vector<int> vis(V,0), pathVis(V,0);

    for(int i=0;i<V;i++) {
        if(!vis[i]) {
            if(dfs(i, adj, vis, pathVis)) {
                cout << "Cycle Found";
                return 0;
            }
        }
    }

    cout << "No Cycle";
}