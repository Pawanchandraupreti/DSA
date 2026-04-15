// Palindrome Partitioning (Min Cuts)

#include <iostream>
#include <algorithm>
using namespace std;

bool isPal(string s, int i, int j) {
    while(i < j)
        if(s[i++] != s[j--])
            return false;
    return true;
}

int main() {

    string s = "aab";
    int n = s.length();

    int dp[100];

    for(int i=0;i<n;i++) {
        dp[i] = i;

        for(int j=0;j<=i;j++) {
            if(isPal(s, j, i)) {
                dp[i] = (j==0) ? 0 : min(dp[i], dp[j-1] + 1);
            }
        }
    }

    cout << dp[n-1];
}





