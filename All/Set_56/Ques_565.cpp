// Isomorphic Strings

#include <bits/stdc++.h>
using namespace std;

int main() {
    string a, b;
    cin >> a >> b;
    if (a.size() != b.size()) {
        cout << "false\n";
        return 0;
    }
    unordered_map<char, char> mp;
    unordered_set<char> seen;
    for (int i = 0; i < (int)a.size(); i++) {
        if (mp.count(a[i])) {
            if (mp[a[i]] != b[i]) {
                cout << "false\n";
                return 0;
            }
        } else {
            if (seen.count(b[i])) {
                cout << "false\n";
                return 0;
            }
            mp[a[i]] = b[i];
            seen.insert(b[i]);
        }
    }
    cout << "true\n";
    return 0;
}

