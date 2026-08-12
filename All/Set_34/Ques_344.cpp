// 0/1 Knapsack maximum value

#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, W; if(!(cin>>n>>W)) return 0;
    vector<int> w(n), v(n);
    for(int i=0;i<n;++i) cin>>w[i];
    for(int i=0;i<n;++i) cin>>v[i];
    vector<long long> dp(W+1, 0);
    for(int i=0;i<n;++i){ for(int cap=W; cap>=w[i]; --cap) dp[cap] = max(dp[cap], dp[cap-w[i]] + v[i]); }
    cout<<dp[W];
    return 0;
}
