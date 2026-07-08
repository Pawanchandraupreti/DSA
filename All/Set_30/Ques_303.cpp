// Check whether a string is a palindrome

#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    if (!(cin >> s)) return 0;

    int left = 0, right = (int)s.size() - 1;
    bool isPalindrome = true;
    while (left < right) {
        if (s[left] != s[right]) {
            isPalindrome = false;
            break;
        }
        ++left;
        --right;
    }

    cout << (isPalindrome ? "Yes" : "No");
    return 0;
}
