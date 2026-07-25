// Count vowels in a string

#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    if (!(cin >> s)) return 0;

    int countVowels = 0;
    for (char c : s) {
        char ch = tolower(static_cast<unsigned char>(c));
        if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
            ++countVowels;
        }
    }

    cout << countVowels;
    return 0;
}

