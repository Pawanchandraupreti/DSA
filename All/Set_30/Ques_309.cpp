// Check if two strings are anagrams

#include <bits/stdc++.h>
using namespace std;

int main() {
    string a, b;
    if (!(cin >> a >> b)) return 0;

    if (a.size() != b.size()) {
        cout << "No";
        return 0;
    }

    vector<int> cnt(256, 0);
    for (char c : a) ++cnt[(unsigned char)c];
    for (char c : b) --cnt[(unsigned char)c];

    for (int x : cnt) {
        if (x != 0) {
            cout << "No";
            return 0;
        }
    }

    cout << "Yes";
    return 0;
}

