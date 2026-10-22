// Minimum Swaps for Balanced Brackets

#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    int balance = 0, swaps = 0, open = 0;
    for (char ch : s) {
        if (ch == '[') {
            open++;
            balance++;
        } else {
            balance--;
        }
        if (balance < 0) {
            swaps++;
            balance = 1;
        }
    }
    cout << swaps << '\n';
    return 0;
}
