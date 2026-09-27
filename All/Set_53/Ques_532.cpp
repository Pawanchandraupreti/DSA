// Largest Odd Number in a String

#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    int end = (int)s.size() - 1;
    while (end >= 0 && (s[end] - '0') % 2 == 0) end--;
    cout << (end < 0 ? "" : s.substr(0, end + 1)) << '\n';
    return 0;
}
