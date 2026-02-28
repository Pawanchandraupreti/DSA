// Climbing Stairs

#include <iostream>
using namespace std;

int main() {
    int n = 5;

    if (n <= 2) {
        cout << n;
        return 0;
    }

    int prev2 = 1, prev1 = 2;

    for (int i = 3; i <= n; i++) {
        int curr = prev1 + prev2;
        prev2 = prev1;
        prev1 = curr;
    }

    cout << prev1;
    return 0;
}