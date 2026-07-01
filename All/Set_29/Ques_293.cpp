// Subset sum with reconstruction

#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n,S; if(!(cin>>n>>S)) return 0;
    vector<int> a(n); for(int i=0;i<n;++i) cin>>a[i];
    vector<vector<bool>> dp(n+1, vector<bool>(S+1,false)); dp[0][0]=true;
    for(int i=0;i<n;++i) for(int s=S;s>=a[i];--s) if(dp[i][s-a[i]]) dp[i+1][s]=true;
    if(!dp[n][S]){ cout<<-1; return 0; }
    vector<int> chosen; int s=S;
    for(int i=n;i>0&&s>0;--i) if(dp[i-1][s-a[i-1]]) { chosen.push_back(i-1); s-=a[i-1]; }
    reverse(chosen.begin(), chosen.end());
    for(int idx:chosen) cout<<idx<<' '; return 0;
}

