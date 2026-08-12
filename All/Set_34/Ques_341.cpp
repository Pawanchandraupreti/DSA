// Fenwick Tree (Binary Indexed Tree) - point update, range sum

#include <bits/stdc++.h>
using namespace std;

struct Fenwick {
    int n; vector<long long> bit;
    Fenwick(int _n=0){ n=_n; bit.assign(n+1,0); }
    void add(int idx,long long val){ for(;idx<=n;idx+=idx&-idx) bit[idx]+=val; }
    long long sum(int idx){ long long r=0; for(;idx>0;idx-=idx&-idx) r+=bit[idx]; return r; }
    long long range_sum(int l,int r){ if(r<l) return 0; return sum(r)-sum(l-1); }
};

int main(){
    int n,q; if(!(cin>>n>>q)) return 0;
    Fenwick fw(n);
    for(int i=1;i<=n;++i){ long long x; cin>>x; fw.add(i,x); }
    while(q--){
        int t; cin>>t;
        if(t==1){ int idx; long long val; cin>>idx>>val; fw.add(idx,val); }
        else if(t==2){ int l,r; cin>>l>>r; cout<<fw.range_sum(l,r)<<"\n"; }
    }
    return 0;
}
