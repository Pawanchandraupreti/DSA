// Longest Happy Prefix

#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    vector<int> prefix(s.size());
    for (int i = 1; i < (int)s.size(); i++) {
        int j = prefix[i - 1];
        while (j && s[i] != s[j]) j = prefix[j - 1];
        if (s[i] == s[j]) j++;
        prefix[i] = j;
    }
    cout << s.substr(0, prefix.back()) << '\n';
    return 0;
}
