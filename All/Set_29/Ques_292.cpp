// Strongly connected components with path counting

#include <bits/stdc++.h>
using namespace std;
static const long long MOD = 1000000007LL;

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n,m; if(!(cin>>n>>m)) return 0;
    vector<vector<int>> g(n+1), rg(n+1);
    for(int i=0;i<m;++i){ int u,v; cin>>u>>v; g[u].push_back(v); rg[v].push_back(u); }
    vector<int> vis(n+1,0), st, comp(n+1,-1);
    function<void(int)> dfs1 = [&](int u){ vis[u]=1; for(int v:g[u]) if(!vis[v]) dfs1(v); st.push_back(u); };
    function<void(int,int)> dfs2 = [&](int u,int c){ comp[u]=c; for(int v:rg[u]) if(comp[v]==-1) dfs2(v,c); };
    for(int i=1;i<=n;++i) if(!vis[i]) dfs1(i);
    int cc=0; reverse(st.begin(),st.end());
    for(int u:st) if(comp[u]==-1) dfs2(u, cc++);
    cout << cc; return 0;
}


