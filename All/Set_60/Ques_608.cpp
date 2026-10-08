// Find All Anagrams in a String

#include <bits/stdc++.h>
using namespace std;

int main() {
    string text, pattern;
    cin >> text >> pattern;
    vector<int> need(26), window(26);
    for (char letter : pattern) need[letter - 'a']++;
    for (int i = 0; i < (int)text.size(); i++) {
        window[text[i] - 'a']++;
        if (i >= (int)pattern.size()) window[text[i - pattern.size()] - 'a']--;
        if (window == need) cout << i - pattern.size() + 1 << ' ';
    }
    cout << '\n';
    return 0;
}

