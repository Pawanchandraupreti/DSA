// Minimum Additions for Valid Parentheses

#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    int balance = 0, additions = 0;
    for (char ch : s) {
        if (ch == '(') balance++;
        else if (balance) balance--;
        else additions++;
    }
    cout << additions + balance << '\n';
    return 0;
}
