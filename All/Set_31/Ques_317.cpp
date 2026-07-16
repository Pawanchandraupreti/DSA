// Check if a number is a palindrome (integer)

#include <bits/stdc++.h>
using namespace std;

int main() {
    long long x;
    if (!(cin >> x)) return 0;
    if (x < 0) { cout << "No"; return 0; }
    long long orig = x, rev = 0;
    while (x) { rev = rev * 10 + (x % 10); x /= 10; }
    cout << (rev == orig ? "Yes" : "No");
    return 0;
}


