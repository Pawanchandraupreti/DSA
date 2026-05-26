// Palindrome String Check

#include <iostream>
#include <string>
using namespace std;

bool isPalindrome(const string &s) {
    int i = 0, j = s.size() - 1;
    while (i < j) {
        if (s[i] != s[j]) return false;
        i++; j--;
    }
    return true;
}

int main() {
    string s;
    getline(cin, s);
    if (isPalindrome(s)) cout << "Palindrome";
    else cout << "Not Palindrome";
    return 0;
}
