// Minimum Window Substring Length

#include <bits/stdc++.h>
using namespace std;

int main() {
    string s, target;
    cin >> s >> target;
    vector<int> need(256), have(256);
    for (char ch : target) need[ch]++;

    int left = 0, matched = 0, answer = s.size() + 1;
    for (int right = 0; right < (int)s.size(); right++) {
        have[s[right]]++;
        if (have[s[right]] <= need[s[right]]) matched++;
        while (matched == (int)target.size()) {
            answer = min(answer, right - left + 1);
            if (--have[s[left]] < need[s[left]]) matched--;
            left++;
        }
    }
    cout << (answer == (int)s.size() + 1 ? 0 : answer) << '\n';
    return 0;
}
