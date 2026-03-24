// Minimum Spanning Tree – Prim’s Algorithm

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {

    int V = 5;

    vector<pair<int,int>> adj[5];

    adj[0].push_back({1,2});
    adj[0].push_back({3,6});
    adj[1].push_back({0,2});
    adj[1].push_back({2,3});
    adj[1].push_back({3,8});
    adj[1].push_back({4,5});
    adj[2].push_back({1,3});
    adj[2].push_back({4,7});
    adj[3].push_back({0,6});
    adj[3].push_back({1,8});
    adj[4].push_back({1,5});
    adj[4].push_back({2,7});

    vector<int> vis(V,0);

    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;

    pq.push({0,0});
    int sum = 0;

    while(!pq.empty()) {

        auto [wt,node] = pq.top();
        pq.pop();

        if(vis[node]) continue;

        vis[node] = 1;
        sum += wt;

        for(auto it : adj[node]) {
            if(!vis[it.first])
                pq.push({it.second, it.first});
        }
    }

    cout << sum;
}
