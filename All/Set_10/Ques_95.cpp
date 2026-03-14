// Topological Sort (Kahn's Algorithm)

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {

    int V = 6;

    vector<int> adj[6];

    adj[5].push_back(2);
    adj[5].push_back(0);
    adj[4].push_back(0);
    adj[4].push_back(1);
    adj[2].push_back(3);
    adj[3].push_back(1);

    vector<int> indegree(V,0);

    for(int i=0;i<V;i++)
        for(auto v:adj[i])
            indegree[v]++;

    queue<int> q;

    for(int i=0;i<V;i++)
        if(indegree[i]==0)
            q.push(i);

    while(!q.empty()) {

        int node=q.front();
        q.pop();

        cout<<node<<" ";

        for(auto v:adj[node]) {
            indegree[v]--;

            if(indegree[v]==0)
                q.push(v);
        }
    }
}
