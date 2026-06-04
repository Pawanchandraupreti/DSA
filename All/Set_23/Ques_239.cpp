// Palindrome check for string

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    string s; if (!(cin >> s)) return 0;
    string t = s; reverse(t.begin(), t.end());
    cout << (s == t ? "YES" : "NO");
    return 0;
}


