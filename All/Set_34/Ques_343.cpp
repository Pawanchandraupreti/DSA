// Longest palindromic substring length (Manacher's algorithm)

#include <bits/stdc++.h>
using namespace std;

int main(){
    string s; if(!getline(cin,s)) return 0; if(s.size()==0){ cout<<0; return 0; }
    string t = "#";
    for(char c: s){ t.push_back(c); t.push_back('#'); }
    int n = t.size();
    vector<int> p(n);
    int c=0,r=0;
    for(int i=0;i<n;++i){ int mir=2*c-i; if(i<r) p[i]=min(r-i, p[mir]); while(i-1-p[i]>=0 && i+1+p[i]<n && t[i-1-p[i]]==t[i+1+p[i]]) p[i]++; if(i+p[i]>r){ c=i; r=i+p[i]; } }
    int best=0; for(int x: p) best = max(best, x);
    cout<<best;
    return 0;
}
