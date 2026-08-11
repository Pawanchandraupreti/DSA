// Count walks of length k from 1 to n (matrix exponentiation)

#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1000000007LL;

vector<vector<long long>> mul(const vector<vector<long long>>& A, const vector<vector<long long>>& B){
    int n=A.size(); vector<vector<long long>> C(n, vector<long long>(n));
    for(int i=0;i<n;++i) for(int k=0;k<n;++k) if(A[i][k]) for(int j=0;j<n;++j) C[i][j]=(C[i][j]+A[i][k]*B[k][j])%MOD;
    return C;
}

vector<vector<long long>> mpow(vector<vector<long long>> A, long long e){
    int n=A.size(); vector<vector<long long>> R(n, vector<long long>(n)); for(int i=0;i<n;++i) R[i][i]=1;
    while(e){ if(e&1) R=mul(R,A); A=mul(A,A); e>>=1; }
    return R;
}

int main(){
    int n, m; long long k; if(!(cin>>n>>m>>k)) return 0;
    vector<vector<long long>> A(n, vector<long long>(n));
    for(int i=0;i<m;++i){ int u,v; cin>>u>>v; A[u-1][v-1]=(A[u-1][v-1]+1)%MOD; }
    auto Ak = mpow(A, k);
    cout << Ak[0][n-1] % MOD;
    return 0;
}

