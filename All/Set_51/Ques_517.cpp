// Climbing Stairs

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    long long one = 1, two = 1;
    for (int i = 2; i <= n; i++) {
        long long current = one + two;
        two = one;
        one = current;
    }

    cout << one << '\n';
    return 0;
}
