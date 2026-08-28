// Palindrome Partitioning II

#include <bits/stdc++.h>
using namespace std;

int minCut(const string& text) {
    int length = (int)text.size();
    vector<vector<bool>> palindrome(length, vector<bool>(length, false));
    vector<int> cuts(length + 1, INT_MAX);
    cuts[0] = -1;

    for (int left = length - 1; left >= 0; --left) {
        for (int right = left; right < length; ++right) {
            palindrome[left][right] = text[left] == text[right] &&
                                      (right - left < 2 || palindrome[left + 1][right - 1]);
            if (palindrome[left][right]) {
                cuts[right + 1] = min(cuts[right + 1], cuts[left] + 1);
            }
        }
    }

    return cuts[length];
}

int main() {
    string text;
    cin >> text;

    cout << minCut(text);
    return 0;
}
