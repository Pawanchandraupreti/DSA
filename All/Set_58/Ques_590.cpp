// Number of 1 Bits

#include <bits/stdc++.h>
using namespace std;

int main() {
    unsigned int number;
    cin >> number;
    int bits = 0;
    while (number) {
        number &= number - 1;
        bits++;
    }
    cout << bits << '\n';
    return 0;
}

