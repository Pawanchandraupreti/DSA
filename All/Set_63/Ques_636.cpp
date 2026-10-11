// Climbing Stairs

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    if (n <= 2) {
        cout << n << '\n';
        return 0;
    }

    int one = 1, two = 2;
    for (int i = 3; i <= n; i++) {
        int next = one + two;
        one = two;
        two = next;
    }
    cout << two << '\n';
    return 0;
}
