// Check if two strings are anagrams

#include <bits/stdc++.h>
using namespace std;

int main() {
    string a, b;
    if (!(cin >> a >> b)) return 0;

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    cout << (a == b ? "Yes" : "No");
    return 0;
}
