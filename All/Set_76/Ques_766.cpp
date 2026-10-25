// Shortest Palindrome

#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    string reversed = s;
    reverse(reversed.begin(), reversed.end());
    string combined = s + '#' + reversed;
    vector<int> prefix(combined.size());
    for (int i = 1; i < (int)combined.size(); i++) {
        int j = prefix[i - 1];
        while (j && combined[i] != combined[j]) j = prefix[j - 1];
        if (combined[i] == combined[j]) j++;
        prefix[i] = j;
    }
    cout << reversed.substr(0, s.size() - prefix.back()) + s << '\n';
    return 0;
}
