// Coin Change – Number of Ways

#include <iostream>
using namespace std;

int main() {
    int coins[] = {1,2,5};
    int n = 3;
    int amount = 5;

    int dp[6]={0};
    dp[0]=1;

    for(int i=0;i<n;i++){
        for(int j=coins[i]; j<=amount; j++){
            dp[j]+=dp[j-coins[i]];
        }
    }

    cout<<dp[amount];
}