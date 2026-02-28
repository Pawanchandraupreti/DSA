// Fibonacci (DP – Bottom Up)

#include <iostream>
using namespace std;

int main() {
    int n = 10;

    if (n <= 1) {
        cout << n;
        return 0;
    }

    int prev2 = 0, prev1 = 1;

    for (int i = 2; i <= n; i++) {
        int curr = prev1 + prev2;
        prev2 = prev1;
        prev1 = curr;
    }

    cout << prev1;
    return 0;
}