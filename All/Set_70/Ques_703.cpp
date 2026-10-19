// Find All Anagram Start Indices

#include <bits/stdc++.h>
using namespace std;

int main() {
    string s, pattern;
    cin >> s >> pattern;
    vector<int> need(26), window(26), answer;
    for (char ch : pattern) need[ch - 'a']++;
    for (int i = 0; i < (int)s.size(); i++) {
        window[s[i] - 'a']++;
        if (i >= (int)pattern.size()) window[s[i - pattern.size()] - 'a']--;
        if (i + 1 >= (int)pattern.size() && window == need) answer.push_back(i - pattern.size() + 1);
    }
    for (int index : answer) cout << index << ' ';
    cout << '\n';
    return 0;
}
