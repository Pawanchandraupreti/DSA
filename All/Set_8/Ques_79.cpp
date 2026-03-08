// Longest Common Substring

#include <iostream>
using namespace std;

int main() {
    string s1="abcdxyz";
    string s2="xyzabcd";

    int n=s1.length();
    int m=s2.length();

    int dp[100][100]={0};
    int ans=0;

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(s1[i-1]==s2[j-1]){
                dp[i][j]=1+dp[i-1][j-1];
                ans=max(ans,dp[i][j]);
            }
            else
                dp[i][j]=0;
        }
    }

    cout<<ans;
}

