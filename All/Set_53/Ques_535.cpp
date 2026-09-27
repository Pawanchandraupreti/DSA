// Minimum Additions for Valid Parentheses

#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    int open = 0, answer = 0;
    for (char c : s) {
        if (c == '(') open++;
        else if (open > 0) open--;
        else answer++;
    }

    cout << answer + open << '\n';
    return 0;
}
