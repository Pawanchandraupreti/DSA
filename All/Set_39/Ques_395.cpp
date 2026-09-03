// Regular Expression Matching

#include <bits/stdc++.h>
using namespace std;

bool isMatch(const string& text, const string& pattern) {
    int textLength = (int)text.size();
    int patternLength = (int)pattern.size();
    vector<vector<bool>> dp(textLength + 1, vector<bool>(patternLength + 1, false));
    dp[0][0] = true;

    for (int patternIndex = 2; patternIndex <= patternLength; ++patternIndex) {
        if (pattern[patternIndex - 1] == '*') {
            dp[0][patternIndex] = dp[0][patternIndex - 2];
        }
    }

    for (int textIndex = 1; textIndex <= textLength; ++textIndex) {
        for (int patternIndex = 1; patternIndex <= patternLength; ++patternIndex) {
            char patternCharacter = pattern[patternIndex - 1];
            if (patternCharacter == '.' || patternCharacter == text[textIndex - 1]) {
                dp[textIndex][patternIndex] = dp[textIndex - 1][patternIndex - 1];
            } else if (patternCharacter == '*' && patternIndex >= 2) {
                dp[textIndex][patternIndex] = dp[textIndex][patternIndex - 2];
                char repeatedCharacter = pattern[patternIndex - 2];
                if (repeatedCharacter == '.' || repeatedCharacter == text[textIndex - 1]) {
                    dp[textIndex][patternIndex] = dp[textIndex][patternIndex] || dp[textIndex - 1][patternIndex];
                }
            }
        }
    }

    return dp[textLength][patternLength];
}

int main() {
    string text, pattern;
    cin >> text >> pattern;

    cout << (isMatch(text, pattern) ? "true" : "false");
    return 0;
}