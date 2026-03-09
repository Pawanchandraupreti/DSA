// Minimum operations (insert, delete, replace) to convert one string into another.

#include <iostream>
using namespace std;

int main() {
    string s1 = "horse";
    string s2 = "ros";

    int n = s1.length();
    int m = s2.length();

    int dp[6][4];

    for(int i=0;i<=n;i++) dp[i][0]=i;
    for(int j=0;j<=m;j++) dp[0][j]=j;

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(s1[i-1]==s2[j-1])
                dp[i][j]=dp[i-1][j-1];
            else
                dp[i][j]=1+min(dp[i-1][j],min(dp[i][j-1],dp[i-1][j-1]));
        }
    }

    cout<<dp[n][m];
}

