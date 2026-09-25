// Longest Palindromic Substring

#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    int start = 0, best = 1;

    auto expand = [&](int left, int right) {
        while (left >= 0 && right < (int)s.size() && s[left] == s[right]) {
            if (right - left + 1 > best) {
                start = left;
                best = right - left + 1;
            }
            left--;
            right++;
        }
    };

    for (int i = 0; i < (int)s.size(); i++) {
        expand(i, i);
        expand(i, i + 1);
    }

    cout << s.substr(start, best) << '\n';
    return 0;
}
