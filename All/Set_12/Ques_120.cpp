// Egg Dropping Problem

#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int dp[100][100];

int solve(int eggs, int floors) {

    if(floors == 0 || floors == 1)
        return floors;

    if(eggs == 1)
        return floors;

    if(dp[eggs][floors] != -1)
        return dp[eggs][floors];

    int ans = 1e9;

    for(int k=1;k<=floors;k++) {

        int temp = 1 + max(
            solve(eggs-1, k-1),
            solve(eggs, floors-k)
        );

        ans = min(ans, temp);
    }

    return dp[eggs][floors] = ans;
}

int main() {

    memset(dp, -1, sizeof(dp));

    cout << solve(2, 10);
}
