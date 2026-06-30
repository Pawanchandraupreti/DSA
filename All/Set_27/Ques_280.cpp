// Convex hull (Graham scan) output hull points in CCW

#include <bits/stdc++.h>
using namespace std; using ll = long long;
struct P{ ll x,y; };
ll cross(const P &a,const P &b,const P &c){ return (b.x-a.x)*(c.y-a.y)-(b.y-a.y)*(c.x-a.x); }

int main(){ ios::sync_with_stdio(false); cin.tie(nullptr); int n; if(!(cin>>n)) return 0; vector<P> pts(n); for(int i=0;i<n;++i) cin>>pts[i].x>>pts[i].y; sort(pts.begin(), pts.end(), [](const P&a,const P&b){ return a.x<b.x || (a.x==b.x && a.y<b.y); }); if(n<=1){ for(auto &p:pts) cout<<p.x<<" "<<p.y<<"\n"; return 0; }
    vector<P> lo, hi;
    for(auto &p: pts){ while(lo.size()>=2 && cross(lo[lo.size()-2], lo.back(), p) <= 0) lo.pop_back(); lo.push_back(p); }
    for(int i=(int)pts.size()-1;i>=0;--i){ auto &p=pts[i]; while(hi.size()>=2 && cross(hi[hi.size()-2], hi.back(), p) <= 0) hi.pop_back(); hi.push_back(p); }
    lo.pop_back(); hi.pop_back(); vector<P> hull = lo; hull.insert(hull.end(), hi.begin(), hi.end()); cout<<hull.size()<<"\n"; for(auto &p: hull) cout<<p.x<<" "<<p.y<<"\n"; return 0; }



