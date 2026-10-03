// Length of Last Word

#include <bits/stdc++.h>
using namespace std;

int main() {
    string text;
    getline(cin >> ws, text);
    int length = 0;
    for (int i = (int)text.size() - 1; i >= 0 && text[i] == ' '; i--);
    for (int i = (int)text.size() - 1; i >= 0 && text[i] != ' '; i--) length++;
    cout << length << '\n';
    return 0;
}
