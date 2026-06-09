// Minimum cost to connect sticks (use min-heap)

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; if(!(cin>>n)) return 0;
    priority_queue<ll, vector<ll>, greater<ll>> pq;
    for(int i=0;i<n;++i){ ll x; cin>>x; pq.push(x); }
    ll cost = 0;
    while(pq.size() > 1){
        ll a = pq.top(); pq.pop();
        ll b = pq.top(); pq.pop();
        cost += a + b;
        pq.push(a+b);
    }
    cout<<cost;
    return 0;
}
