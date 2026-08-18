// Count vowels in a string

#include <bits/stdc++.h>
using namespace std;

int countVowels(const string& s) {
    int vowels = 0;
    for (char ch : s) {
        char c = tolower(ch);
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
            ++vowels;
        }
    }
    return vowels;
}

int main() {
    string s;
    cin >> s;

    cout << countVowels(s);
    return 0;
}
