// Valid Anagram

#include <bits/stdc++.h>
using namespace std;

int main() {
    string a, b;
    cin >> a >> b;

    if (a.size() != b.size()) {
        cout << "false\n";
        return 0;
    }

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    cout << (a == b ? "true" : "false") << '\n';
    return 0;
}
