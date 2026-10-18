// Valid Palindrome After One Deletion

#include <bits/stdc++.h>
using namespace std;

bool palindrome(const string &s, int left, int right) {
    while (left < right) {
        if (s[left++] != s[right--]) return false;
    }
    return true;
}

int main() {
    string s;
    cin >> s;
    int left = 0, right = s.size() - 1;
    while (left < right && s[left] == s[right]) {
        left++;
        right--;
    }
    cout << (left >= right || palindrome(s, left + 1, right) || palindrome(s, left, right - 1) ? "YES" : "NO") << '\n';
    return 0;
}
