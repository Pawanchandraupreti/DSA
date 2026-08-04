// Find the factorial of a number

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    if (!(cin >> n)) return 0;

    long long fact = 1;
    for (int i = 2; i <= n; ++i) fact *= i;

    cout << fact;
    return 0;
}
