// Count Palindromic Substrings

#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    int answer = 0;
    for (int center = 0; center < (int)s.size(); center++) {
        for (int gap : {0, 1}) {
            int left = center, right = center + gap;
            while (left >= 0 && right < (int)s.size() && s[left--] == s[right++]) answer++;
        }
    }
    cout << answer << '\n';
    return 0;
}
