// Longest Substring Without Repeating Characters

#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;

int main() {
    string s = "abcabcbb";
    
    unordered_map<char, int> charIndex;
    int maxLen = 0;
    int left = 0;
    
    for(int right = 0; right < s.length(); right++) {
        if(charIndex.find(s[right]) != charIndex.end() && charIndex[s[right]] >= left) {
            left = charIndex[s[right]] + 1;
        }
        charIndex[s[right]] = right;
        maxLen = max(maxLen, right - left + 1);
    }
    
    cout << "String: " << s << endl;
    cout << "Length of Longest Substring Without Repeating Characters: " << maxLen << endl;
    
    return 0;
}

