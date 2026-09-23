// Palindromic Substrings

#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    int answer = 0;

    for (int center = 0; center < (int)s.size(); center++) {
        for (int left = center, right = center; left >= 0 && right < (int)s.size() && s[left] == s[right]; left--, right++) answer++;
        for (int left = center, right = center + 1; left >= 0 && right < (int)s.size() && s[left] == s[right]; left--, right++) answer++;
    }

    cout << answer << '\n';
    return 0;
}
