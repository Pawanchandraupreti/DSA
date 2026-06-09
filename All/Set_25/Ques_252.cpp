// K-th smallest subarray sum (array of non-negative integers)

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

long long count_leq(const vector<ll>& a, ll x){
    int n = (int)a.size();
    long long cnt = 0;
    int r = 0; ll cur = 0;
    for(int l=0;l<n;++l){
        while(r<n && cur + a[r] <= x){ cur += a[r++]; }
        cnt += (r - l);
        if(r==l) ++r; else cur -= a[l];
    }
    return cnt;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; long long k; if(!(cin>>n>>k)) return 0;
    vector<ll> a(n); ll sum=0;
    for(int i=0;i<n;++i){ cin>>a[i]; sum+=a[i]; }
    ll lo = 0, hi = sum, ans = hi;
    while(lo<=hi){
        ll mid = lo + (hi-lo)/2;
        if(count_leq(a, mid) >= k){ ans = mid; hi = mid-1; }
        else lo = mid+1;
    }
    cout<<ans;
    return 0;
}
