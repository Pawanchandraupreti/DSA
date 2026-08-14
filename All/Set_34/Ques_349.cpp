// Count vowels and consonants in a string

#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    if (!getline(cin, s)) return 0;

    int vowels = 0, consonants = 0;
    for (char c : s) {
        c = tolower(c);
        if (c >= 'a' && c <= 'z') {
            if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') ++vowels;
            else ++consonants;
        }
    }

    cout << vowels << ' ' << consonants;
    return 0;
}


