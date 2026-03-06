// Longest Palindromic Subsequence

#include <iostream>
using namespace std;

int main() {
    string s = "bbbab";
    int n = s.length();

    int dp[100][100];

    for(int i=0;i<n;i++)
        dp[i][i]=1;

    for(int len=2; len<=n; len++){
        for(int i=0;i<n-len+1;i++){
            int j=i+len-1;

            if(s[i]==s[j]){
                if(len==2)
                    dp[i][j]=2;
                else
                    dp[i][j]=2+dp[i+1][j-1];
            }
            else
                dp[i][j]=max(dp[i+1][j],dp[i][j-1]);
        }
    }

    cout<<dp[0][n-1];
}