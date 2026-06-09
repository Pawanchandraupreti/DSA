// Number of distinct elements in every window of size k

#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,k; if(!(cin>>n>>k)) return 0;
    vector<long long> a(n);
    for(int i=0;i<n;++i) cin>>a[i];
    unordered_map<long long,int> cnt;
    vector<int> res;
    for(int i=0;i<n;++i){
        cnt[a[i]]++;
        if(i>=k) {
            if(--cnt[a[i-k]]==0) cnt.erase(a[i-k]);
        }
        if(i>=k-1) res.push_back((int)cnt.size());
    }
    for(size_t i=0;i<res.size();++i){ if(i) cout<<" "; cout<<res[i]; }
    return 0;
}
