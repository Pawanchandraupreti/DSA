// Minimum Deletions for Balanced String

#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    int b = 0, answer = 0;
    for (char ch : s) {
        if (ch == 'b') b++;
        else answer = min(answer + 1, b);
    }
    cout << answer << '\n';
    return 0;
}
