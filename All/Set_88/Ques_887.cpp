// Maximum XOR Subset

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    const int bits = 60;
    vector<unsigned long long> basis(bits);
    for (int i = 0; i < n; i++) {
        unsigned long long value;
        cin >> value;
        for (int bit = bits - 1; bit >= 0; bit--) {
            if (!(value >> bit & 1)) continue;
            if (!basis[bit]) { basis[bit] = value; break; }
            value ^= basis[bit];
        }
    }
    unsigned long long answer = 0;
    for (int bit = bits - 1; bit >= 0; bit--) answer = max(answer, answer ^ basis[bit]);
    cout << answer << '\n';
    return 0;
}
