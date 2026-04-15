// Burst Balloons

#include <iostream>
#include <algorithm>
using namespace std;

int main() {

    int nums[] = {3,1,5,8};
    int n = 4;

    int arr[6];
    arr[0] = arr[n+1] = 1;

    for(int i=0;i<n;i++)
        arr[i+1] = nums[i];

    int dp[6][6] = {0};

    for(int len=1; len<=n; len++) {
        for(int i=1;i<=n-len+1;i++) {
            int j = i + len - 1;

            for(int k=i;k<=j;k++) {
                dp[i][j] = max(dp[i][j],
                               arr[i-1]*arr[k]*arr[j+1] +
                               dp[i][k-1] + dp[k+1][j]);
            }
        }
    }

    
    cout << dp[1][n];
}


