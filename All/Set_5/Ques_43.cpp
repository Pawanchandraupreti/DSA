// Check Palindrome Using Recursion

#include <iostream>
using namespace std;

bool isPalindrome(string &s, int l, int r) {
    if (l >= r) return true;
    if (s[l] != s[r]) return false;
    return isPalindrome(s, l + 1, r - 1);
}

int main() {
    string s = "madam";
    cout << (isPalindrome(s, 0, s.length() - 1) ? "Yes" : "No");
    return 0;
}

