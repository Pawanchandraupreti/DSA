// Minimum Window Substring

#include <bits/stdc++.h>
using namespace std;

string minWindow(const string& text, const string& pattern) {
    if (pattern.size() > text.size()) return "";

    unordered_map<char, int> patternCount, windowCount;
    for (char letter : pattern) patternCount[letter]++;

    int required = (int)patternCount.size();
    int formed = 0;
    int left = 0;
    int minLength = INT_MAX;
    int minLeft = 0;

    for (int right = 0; right < (int)text.size(); ++right) {
        char letter = text[right];
        windowCount[letter]++;

        if (patternCount.count(letter) && windowCount[letter] == patternCount[letter]) {
            ++formed;
        }

        while (left <= right && formed == required) {
            if (right - left + 1 < minLength) {
                minLength = right - left + 1;
                minLeft = left;
            }

            char leftLetter = text[left];
            windowCount[leftLetter]--;
            if (patternCount.count(leftLetter) && windowCount[leftLetter] < patternCount[leftLetter]) {
                --formed;
            }
            ++left;
        }
    }

    return minLength == INT_MAX ? "" : text.substr(minLeft, minLength);
}

int main() {
    string text, pattern;
    cin >> text >> pattern;

    cout << minWindow(text, pattern);
    return 0;
}