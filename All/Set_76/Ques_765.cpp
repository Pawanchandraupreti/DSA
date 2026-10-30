// Check Valid Number

#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    bool digit = false, exponentDigit = true, dot = false, exponent = false;
    for (int i = 0; i < (int)s.size(); i++) {
        char ch = s[i];
        if (isdigit(ch)) digit = exponentDigit = true;
        else if (ch == '.') {
            if (dot || exponent) {
                cout << "NO\n";
                return 0;
            }
            dot = true;
        } else if (ch == 'e' || ch == 'E') {
            if (exponent || !digit) {
                cout << "NO\n";
                return 0;
            }
            exponent = true;
            exponentDigit = false;
        } else if (ch == '+' || ch == '-') {
            if (i && s[i - 1] != 'e' && s[i - 1] != 'E') {
                cout << "NO\n";
                return 0;
            }
        } else {
            cout << "NO\n";
            return 0;
        }
    }
    cout << (digit && exponentDigit ? "YES" : "NO") << '\n';
    return 0;
}

