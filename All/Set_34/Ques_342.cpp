// Minimum number of swaps required to sort an array

#include <bits/stdc++.h>
using namespace std;

int main(){
    int n; if(!(cin>>n)) return 0;
    vector<long long> a(n);
    for(int i=0;i<n;++i) cin>>a[i];
    vector<pair<long long,int>> v;
    for(int i=0;i<n;++i) v.emplace_back(a[i], i);
    sort(v.begin(), v.end());
    vector<int> vis(n,0);
    int swaps=0;
    for(int i=0;i<n;++i){ if(vis[i]||v[i].second==i) continue; int cycle=0; int j=i; while(!vis[j]){ vis[j]=1; j=v[j].second; ++cycle; } if(cycle>0) swaps += cycle-1; }
    cout<<swaps;
    return 0;
}
