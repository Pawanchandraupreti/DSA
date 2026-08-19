// Check whether two strings are anagrams

#include <bits/stdc++.h>
using namespace std;

bool areAnagrams(const string& first, const string& second) {
    if (first.size() != second.size()) {
        return false;
    }

    array<int, 256> frequency{};
    for (unsigned char ch : first) {
        ++frequency[ch];
    }
    for (unsigned char ch : second) {
        --frequency[ch];
    }

    for (int count : frequency) {
        if (count != 0) {
            return false;
        }
    }
    return true;
}

int main() {
    string first, second;
    cin >> first >> second;

    cout << (areAnagrams(first, second) ? 1 : 0);
    return 0;
}
