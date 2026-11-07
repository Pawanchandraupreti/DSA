// Minimum Changes for Alternating Binary String

#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    int first = 0, second = 0;
    for (int i = 0; i < (int)s.size(); i++) {
        first += s[i] - '0' != i % 2;
        second += s[i] - '0' != (i + 1) % 2;
    }
    cout << min(first, second) << '\n';
    return 0;
}
