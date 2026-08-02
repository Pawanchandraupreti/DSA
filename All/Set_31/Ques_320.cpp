// Count set bits in a number

#include <bits/stdc++.h>
using namespace std;

int main() {
    unsigned long long x;
    if (!(cin >> x)) return 0;
    cout << __builtin_popcountll(x);
    return 0;
}


