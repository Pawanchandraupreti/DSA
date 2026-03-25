// Bridges in Graph (Tarjan’s Algorithm)

#include <iostream>
#include <vector>
using namespace std;

int timer = 0;

void dfs(int node, int parent, vector<int>& vis, vector<int>& tin,
         vector<int>& low, vector<int> adj[]) {

    vis[node] = 1;
    tin[node] = low[node] = timer++;

    for(auto it : adj[node]) {

        if(it == parent) continue;

        if(!vis[it]) {
            dfs(it, node, vis, tin, low, adj);

            low[node] = min(low[node], low[it]);

            if(low[it] > tin[node])
                cout << node << " - " << it << endl;
        }
        else {
            low[node] = min(low[node], tin[it]);
        }
    }
}

int main() {

    int V = 5;
    vector<int> adj[5];

    adj[0].push_back(1);
    adj[1].push_back(0);
    adj[1].push_back(2);
    adj[2].push_back(1);
    adj[2].push_back(0);
    adj[0].push_back(2);
    adj[1].push_back(3);
    adj[3].push_back(1);
    adj[3].push_back(4);
    adj[4].push_back(3);

    vector<int> vis(V,0), tin(V), low(V);

    dfs(0, -1, vis, tin, low, adj);
}