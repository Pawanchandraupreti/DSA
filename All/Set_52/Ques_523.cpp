// Minimum Window Substring

#include <bits/stdc++.h>
using namespace std;

int main() {
    string s, t;
    cin >> s >> t;
    vector<int> need(256, 0);
    for (char c : t) need[c]++;

    int missing = t.size(), left = 0, start = 0, length = INT_MAX;
    for (int right = 0; right < (int)s.size(); right++) {
        if (need[s[right]] > 0) missing--;
        need[s[right]]--;
        while (missing == 0) {
            if (right - left + 1 < length) {
                start = left;
                length = right - left + 1;
            }
            need[s[left]]++;
            if (need[s[left]] > 0) missing++;
            left++;
        }
    }

    cout << (length == INT_MAX ? "" : s.substr(start, length)) << '\n';
    return 0;
}
