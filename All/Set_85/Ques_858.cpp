// Find Winner in Circular Game

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, step;
    cin >> n >> step;
    int winner = 0;
    for (int i = 2; i <= n; i++) winner = (winner + step) % i;
    cout << winner + 1 << '\n';
    return 0;
}
