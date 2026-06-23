// Maximum flow (Edmonds-Karp)

#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n,m,s,t; if(!(cin>>n>>m>>s>>t)) return 0;
    vector<vector<int>> cap(n+1, vector<int>(n+1,0));
    for(int i=0;i<m;++i){ int u,v,c; cin>>u>>v>>c; cap[u][v]+=c; }
    int flow=0;
    while(true){
        vector<int> parent(n+1,-1), vis(n+1,0);
        queue<int> q; q.push(s); vis[s]=1;
        while(!q.empty()){ int u=q.front(); q.pop();
            for(int v=1;v<=n;++v) if(!vis[v] && cap[u][v]>0) { vis[v]=1; parent[v]=u; q.push(v); if(v==t) break; }
        }
        if(parent[t]==-1) break;
        int aug=INT_MAX;
        for(int v=t; v!=s; v=parent[v]) aug = min(aug, cap[parent[v]][v]);
        for(int v=t; v!=s; v=parent[v]) { cap[parent[v]][v]-=aug; cap[v][parent[v]]+=aug; }
        flow+=aug;
    }
    cout << flow; return 0;
}
