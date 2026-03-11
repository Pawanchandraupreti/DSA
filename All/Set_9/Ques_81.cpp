// Finds shortest distance from source to all nodes in a weighted graph.

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    int V = 5;
    
    vector<pair<int,int>> adj[5];
    
    adj[0].push_back({1,2});
    adj[0].push_back({2,4});
    adj[1].push_back({2,1});
    adj[1].push_back({3,7});
    adj[2].push_back({4,3});
    adj[3].push_back({4,1});

    vector<int> dist(V, 1e9);

    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

    dist[0] = 0;
    pq.push({0,0});

    while(!pq.empty()) {
        int d = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        for(auto it : adj[node]) {
            int adjNode = it.first;
            int wt = it.second;

            if(d + wt < dist[adjNode]) {
                dist[adjNode] = d + wt;
                pq.push({dist[adjNode], adjNode});
            }
        }
    }

    for(int i=0;i<V;i++)
        cout<<dist[i]<<" ";
}

