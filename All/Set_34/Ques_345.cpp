// Bellman-Ford: shortest paths and negative cycle detection

#include <bits/stdc++.h>
using namespace std;
const long long INF = (1LL<<60);

int main(){
    int n,m; int source; if(!(cin>>n>>m>>source)) return 0;
    struct Edge{int u,v; long long w;};
    vector<Edge> edges;
    for(int i=0;i<m;++i){ int u,v; long long w; cin>>u>>v>>w; edges.push_back({u,v,w}); }
    vector<long long> dist(n+1, INF); dist[source]=0;
    for(int i=1;i<=n-1;++i){ for(auto &e: edges) if(dist[e.u]!=INF && dist[e.v] > dist[e.u] + e.w) dist[e.v] = dist[e.u] + e.w; }
    bool neg=false;
    for(auto &e: edges) if(dist[e.u]!=INF && dist[e.v] > dist[e.u] + e.w) { neg=true; break; }
    if(neg){ cout<<"Negative Cycle"; return 0; }
    for(int i=1;i<=n;++i){ if(i>1) cout<<' '; if(dist[i]==INF) cout<<-1; else cout<<dist[i]; }
    return 0;
}
