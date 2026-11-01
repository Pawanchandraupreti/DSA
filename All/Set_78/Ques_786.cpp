// Domino Tiling Ways

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    if (n <= 1) {
        cout << 1 << '\n';
        return 0;
    }
    int previousTwo = 1, previousOne = 1;
    for (int i = 2; i <= n; i++) {
        int current = previousOne + previousTwo;
        previousTwo = previousOne;
        previousOne = current;
    }
    cout << previousOne << '\n';
    return 0;
}
