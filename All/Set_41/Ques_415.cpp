// Knuth-Morris-Pratt KMP Algorithm

#include <bits/stdc++.h>
using namespace std;

vector<int> buildFailureFunction(const string& pattern) {
    int m = (int)pattern.length();
    vector<int> failure(m, 0);

    for (int i = 1; i < m; ++i) {
        int j = failure[i - 1];
        while (j > 0 && pattern[i] != pattern[j]) {
            j = failure[j - 1];
        }
        if (pattern[i] == pattern[j]) {
            j++;
        }
        failure[i] = j;
    }
    return failure;
}

vector<int> kmpSearch(const string& text, const string& pattern) {
    vector<int> failure = buildFailureFunction(pattern);
    vector<int> matches;
    int n = (int)text.length();
    int m = (int)pattern.length();
    int j = 0;

    for (int i = 0; i < n; ++i) {
        while (j > 0 && text[i] != pattern[j]) {
            j = failure[j - 1];
        }
        if (text[i] == pattern[j]) {
            j++;
        }
        if (j == m) {
            matches.push_back(i - m + 1);
            j = failure[j - 1];
        }
    }
    return matches;
}

int main() {
    string text, pattern;
    cin >> text >> pattern;

    vector<int> matches = kmpSearch(text, pattern);
    for (int pos : matches) {
        cout << pos << ' ';
    }
    return 0;
}
