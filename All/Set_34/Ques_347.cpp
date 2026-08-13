// Check if a string is a palindrome

#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    if (!getline(cin, s)) return 0;

    int l = 0, r = s.size() - 1;
    while (l < r) {
        if (s[l] != s[r]) {
            cout << "No";
            return 0;
        }
        ++l; --r;
    }

    cout << "Yes";
    return 0;
}
