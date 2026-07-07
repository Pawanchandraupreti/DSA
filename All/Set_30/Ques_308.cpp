// Find first non-repeating character in a string

#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    if (!(cin >> s)) return 0;

    vector<int> cnt(256, 0);
    for (char c : s) ++cnt[(unsigned char)c];

    for (char c : s) {
        if (cnt[(unsigned char)c] == 1) {
            cout << c;
            return 0;
        }
    }

    cout << -1;
    return 0;
}