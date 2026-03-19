// Minimum Window Substring (Sliding Window Hard)

#include <iostream>
#include <unordered_map>
using namespace std;

int main() {

    string s = "ADOBECODEBANC";
    string t = "ABC";

    unordered_map<char,int> mp;

    for(char c : t)
        mp[c]++;

    int left = 0, count = 0;
    int minLen = INT_MAX, start = 0;

    for(int right = 0; right < s.length(); right++) {

        if(mp[s[right]] > 0)
            count++;

        mp[s[right]]--;

        while(count == t.length()) {

            if(right - left + 1 < minLen) {
                minLen = right - left + 1;
                start = left;
            }

            mp[s[left]]++;

            if(mp[s[left]] > 0)
                count--;

            left++;
        }
    }

    cout << s.substr(start, minLen);
}