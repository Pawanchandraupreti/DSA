// Longest Repeating Character Replacement

#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    int k;
    cin >> s >> k;
    vector<int> count(26);
    int left = 0, most = 0, answer = 0;
    for (int right = 0; right < (int)s.size(); right++) {
        most = max(most, ++count[s[right] - 'A']);
        while (right - left + 1 - most > k) count[s[left++] - 'A']--;
        answer = max(answer, right - left + 1);
    }
    cout << answer << '\n';
    return 0;
}
