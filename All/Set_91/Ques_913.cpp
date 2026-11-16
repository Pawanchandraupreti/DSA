// Check if a String is a Palindrome

#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    int l = 0, r = s.size() - 1;
    while (l < r) {
        if (s[l] != s[r]) {
            cout << "NO\n";
            return 0;
        }
        l++;
        r--;
    }
    cout << "YES\n";
    return 0;
}
