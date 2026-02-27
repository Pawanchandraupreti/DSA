// Palindrome Partitioning (Backtracking)

#include <iostream>
using namespace std;

bool isPalindrome(string s, int l, int r) {
    while (l < r)
        if (s[l++] != s[r--])
            return false;
    return true;
}

void solve(string s, int start, string curr) {
    if (start == s.length()) {
        cout << curr << endl;
        return;
    }

    for (int i = start; i < s.length(); i++) {
        if (isPalindrome(s, start, i))
            solve(s, i + 1, curr + s.substr(start, i - start + 1) + " ");
    }
}

int main() {
    solve("aab", 0, "");
    return 0;
}