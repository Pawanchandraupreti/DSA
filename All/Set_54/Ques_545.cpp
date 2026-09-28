// Valid Palindrome

#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    string cleaned;
    for (char c : s) {
        if (isalnum(c)) cleaned.push_back(tolower(c));
    }

    string rev = cleaned;
    reverse(rev.begin(), rev.end());
    cout << (cleaned == rev ? "true" : "false") << '\n';
    return 0;
}
