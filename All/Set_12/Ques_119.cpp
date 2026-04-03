// Rod Cutting Problem

#include <iostream>
#include <algorithm>
using namespace std;

int main() {

    int price[] = {2,5,7,8};
    int n = 4;

    int dp[5] = {0};

    for(int i=1;i<=n;i++) {
        for(int j=0;j<i;j++) {
            dp[i] = max(dp[i], price[j] + dp[i-j-1]);
        }
    }

    cout << dp[n];
}
