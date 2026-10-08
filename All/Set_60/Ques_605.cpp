// Decode Ways

#include <bits/stdc++.h>
using namespace std;

int main() {
    string text;
    cin >> text;
    if (text.empty() || text[0] == '0') {
        cout << 0 << '\n';
        return 0;
    }
    int previousTwo = 1, previousOne = 1;
    for (int i = 1; i < (int)text.size(); i++) {
        int current = 0;
        if (text[i] != '0') current += previousOne;
        int value = stoi(text.substr(i - 1, 2));
        if (value >= 10 && value <= 26) current += previousTwo;
        previousTwo = previousOne;
        previousOne = current;
    }
    cout << previousOne << '\n';
    return 0;
}

