// Maximum Number of Nonoverlapping Palindromes

#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    int length;
    cin >> s >> length;
    int answer = 0, end = -1;
    for (int right = 0; right < (int)s.size(); right++) {
        for (int left = right; left >= 0; left--) {
            if (right - left + 1 < length) continue;
            bool palindrome = true;
            for (int i = left, j = right; i < j; i++, j--) if (s[i] != s[j]) palindrome = false;
            if (palindrome && left > end) { answer++; end = right; break; }
        }
    }
    cout << answer << '\n';
    return 0;
}
