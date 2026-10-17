// Decode Ways

#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    if (s.empty() || s[0] == '0') {
        cout << 0 << '\n';
        return 0;
    }

    int previousTwo = 1, previousOne = 1;
    for (int i = 1; i < (int)s.size(); i++) {
        int current = 0;
        if (s[i] != '0') current += previousOne;
        int number = (s[i - 1] - '0') * 10 + s[i] - '0';
        if (number >= 10 && number <= 26) current += previousTwo;
        previousTwo = previousOne;
        previousOne = current;
    }
    cout << previousOne << '\n';
    return 0;
}
