// Z-Algorithm String Matching

#include <bits/stdc++.h>
using namespace std;

vector<int> computeZ(const string& str) {
    int n = (int)str.length();
    vector<int> z(n);
    z[0] = n;
    int left = 0, right = 0;

    for (int i = 1; i < n; ++i) {
        if (i <= right) {
            z[i] = min(right - i + 1, z[i - left]);
        }
        while (i + z[i] < n && str[z[i]] == str[i + z[i]]) {
            z[i]++;
        }
        if (i + z[i] - 1 > right) {
            left = i;
            right = i + z[i] - 1;
        }
    }
    return z;
}

int main() {
    string text, pattern;
    cin >> text >> pattern;

    string combined = pattern + "$" + text;
    vector<int> z = computeZ(combined);
    int patternLen = (int)pattern.length();

    vector<int> matches;
    for (int i = patternLen + 1; i < (int)combined.length(); ++i) {
        if (z[i] == patternLen) {
            matches.push_back(i - patternLen - 1);
        }
    }

    for (int pos : matches) {
        cout << pos << ' ';
    }
    return 0;
}
