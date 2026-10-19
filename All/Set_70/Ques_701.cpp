// Minimum Flips to Make Binary String Monotone

#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    int ones = 0, flips = 0;
    for (char ch : s) {
        if (ch == '1') ones++;
        else flips = min(flips + 1, ones);
    }
    cout << flips << '\n';
    return 0;
}
