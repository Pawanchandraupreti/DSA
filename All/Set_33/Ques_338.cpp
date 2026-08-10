// Segment tree: point update and range maximum query

#include <bits/stdc++.h>
using namespace std;

struct Seg {
    int n; vector<long long> st;
    Seg(int _n=0){ n=1; while(n<_n) n<<=1; st.assign(2*n, LLONG_MIN); }
    void build(vector<long long>& a){ for(int i=0;i<(int)a.size();++i) st[n+i]=a[i]; for(int i=n-1;i>=1;--i) st[i]=max(st[2*i], st[2*i+1]); }
    void update(int pos, long long val){ pos+=n; st[pos]=val; for(pos>>=1;pos;pos>>=1) st[pos]=max(st[2*pos], st[2*pos+1]); }
    long long query(int l,int r){ l+=n; r+=n; long long res=LLONG_MIN; while(l<=r){ if(l&1) res=max(res,st[l++]); if(!(r&1)) res=max(res,st[r--]); l>>=1; r>>=1; } return res; }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,q; if(!(cin>>n>>q)) return 0;
    vector<long long> a(n);
    for(int i=0;i<n;++i) cin>>a[i];
    Seg seg(n); seg.build(a);
    while(q--) {
        int type; cin>>type;
        if (type==1) { int idx; long long val; cin>>idx>>val; seg.update(idx-1,val); }
        else if (type==2) { int l,r; cin>>l>>r; cout<<seg.query(l-1,r-1)<<"\n"; }
    }
    return 0;
}
