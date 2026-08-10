// Minimum Spanning Tree weight (Kruskal)

#include <bits/stdc++.h>
using namespace std;

struct DSU { int n; vector<int> p; DSU(int n=0):n(n),p(n+1){ iota(p.begin(),p.end(),0);} int find(int x){ return p[x]==x?x:p[x]=find(p[x]); } bool unite(int a,int b){ a=find(a); b=find(b); if(a==b) return false; p[b]=a; return true; } };

int main(){
    int n,m; if(!(cin>>n>>m)) return 0;
    vector<tuple<long long,int,int>> edges;
    for(int i=0;i<m;++i){ int u,v; long long w; cin>>u>>v>>w; edges.emplace_back(w,u,v); }
    sort(edges.begin(), edges.end());
    DSU dsu(n);
    long long total=0; int used=0;
    for(auto &e: edges){ long long w; int u,v; tie(w,u,v)=e; if(dsu.unite(u,v)){ total+=w; ++used; } }
    if (used != n-1) cout << -1; else cout << total;
    return 0;
}
