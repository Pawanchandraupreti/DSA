// Longest Increasing Subsequence with reconstruction

#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; if(!(cin>>n)) return 0;
    vector<long long> a(n);
    for(int i=0;i<n;++i) cin>>a[i];
    vector<long long> d; vector<int> d_idx; vector<int> parent(n,-1);
    for(int i=0;i<n;++i){
        auto it = lower_bound(d.begin(), d.end(), a[i]);
        int pos = int(it - d.begin());
        if(it==d.end()){ d.push_back(a[i]); d_idx.push_back(i); }
        else { *it = a[i]; d_idx[pos]=i; }
        if(pos>0) parent[i] = d_idx[pos-1];
    }
    int len = (int)d.size();
    cout<<len<<"\n";
    int idx = d_idx.empty() ? -1 : d_idx.back();
    vector<long long> lis;
    while(idx!=-1){ lis.push_back(a[idx]); idx = parent[idx]; }
    reverse(lis.begin(), lis.end());
    for(size_t i=0;i<lis.size();++i){ if(i) cout<<" "; cout<<lis[i]; }
    return 0;
}
