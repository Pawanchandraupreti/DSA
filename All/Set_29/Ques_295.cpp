// Topological sort with cycle detection

#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n,m; if(!(cin>>n>>m)) return 0;
    vector<vector<int>> g(n+1); vector<int> indeg(n+1,0);
    for(int i=0;i<m;++i){ int u,v; cin>>u>>v; g[u].push_back(v); indeg[v]++; }
    queue<int> q; vector<int> topo;
    for(int i=1;i<=n;++i) if(indeg[i]==0) q.push(i);
    while(!q.empty()){ int u=q.front(); q.pop(); topo.push_back(u);
        for(int v:g[u]) { indeg[v]--; if(indeg[v]==0) q.push(v); }
    }
    if((int)topo.size()!=n) { cout<<"Cycle detected"; return 0; }
    for(int x:topo) cout<<x<<' '; return 0;
}



