// K-th smallest element in two sorted arrays

#include <bits/stdc++.h>
using namespace std;

int kth(const vector<long long>& a, const vector<long long>& b, int k){
    int n=a.size(), m=b.size();
    int i=0,j=0;
    while(true){
        if(i==n) return b[j+k-1];
        if(j==m) return a[i+k-1];
        if(k==1) return min(a[i], b[j]);
        int ia = min(n, i + k/2);
        int jb = min(m, j + k/2);
        if(a[ia-1] <= b[jb-1]){ k -= (ia-i); i = ia; }
        else { k -= (jb-j); j = jb; }
    }
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n,m; if(!(cin>>n>>m)) return 0; int k; cin>>k;
    vector<long long> a(n), b(m);
    for(int i=0;i<n;++i) cin>>a[i]; for(int j=0;j<m;++j) cin>>b[j];
    cout<<kth(a,b,k);
    return 0;
}


