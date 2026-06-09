// Count inversions in an array (Fenwick / BIT)

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct Fenwick {
    int n; vector<ll> f;
    Fenwick(int n=0): n(n), f(n+1,0) {}
    void add(int i, ll v){ for(; i<=n; i+=i&-i) f[i]+=v; }
    ll sum(int i){ ll s=0; for(; i>0; i-=i&-i) s+=f[i]; return s; }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; if(!(cin>>n)) return 0;
    vector<long long>a(n);
    for(int i=0;i<n;++i) cin>>a[i];
    vector<long long> b = a;
    sort(b.begin(), b.end());
    b.erase(unique(b.begin(), b.end()), b.end());
    Fenwick bit((int)b.size());
    long long inv = 0;
    for(int i=n-1;i>=0;--i){
        int idx = int(lower_bound(b.begin(), b.end(), a[i]) - b.begin()) + 1;
        inv += bit.sum(idx-1);
        bit.add(idx, 1);
    }
    cout<<inv;
    return 0;
}
