// First Unique Character

#include <bits/stdc++.h>
using namespace std;

int main() {
    string text;
    cin >> text;
    vector<int> frequency(256);
    for (char letter : text) frequency[(unsigned char)letter]++;
    for (int i = 0; i < (int)text.size(); i++) {
        if (frequency[(unsigned char)text[i]] == 1) {
            cout << i << '\n';
            return 0;
        }
    }
    cout << -1 << '\n';
    return 0;
}
