// Check if Two Strings Are Anagrams

#include <iostream>
using namespace std;

int main() {
    string s1 = "listen", s2 = "silent";
    int freq[26] = {0};

    for (char c : s1) freq[c - 'a']++;
    for (char c : s2) freq[c - 'a']--;

    bool ok = true;
    for (int i = 0; i < 26; i++) {
        if (freq[i] != 0) {
            ok = false;
            break;
        }
    }

    if (ok) cout << "Anagram";
    else cout << "Not Anagram";

    return 0;
}


