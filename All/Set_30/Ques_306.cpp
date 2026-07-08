// Compute GCD and LCM of two numbers

#include <bits/stdc++.h>
using namespace std;

int main() {
    long long a, b;
    if (!(cin >> a >> b)) return 0;

    long long g = std::gcd(a, b);
    long long l = (a / g) * b;

    cout << g << '\n' << l;
    return 0;
}

