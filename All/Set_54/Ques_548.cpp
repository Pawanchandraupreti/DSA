// ZigZag Conversion

#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    int rows;
    cin >> rows;
    if (rows <= 1) {
        cout << s << '\n';
        return 0;
    }
    vector<string> arr(rows, "");
    int direction = -1, row = 0;
    for (char c : s) {
        arr[row].push_back(c);
        if (row == 0 || row == rows - 1) direction *= -1;
        row += direction;
    }

    string answer;
    for (string &line : arr) answer += line;
    cout << answer << '\n';
    return 0;
}
