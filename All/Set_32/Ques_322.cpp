// Check if a number is even or odd

#include <bits/stdc++.h>
using namespace std;

int main() {
    long long x;
    if (!(cin >> x)) return 0;

    cout << (x % 2 == 0 ? "Even" : "Odd");
    return 0;
}

