// Minimum Swaps to Balance Brackets

#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    int open = 0, close = 0, swaps = 0;

    for (char c : s) {
        if (c == '[') open++;
        else if (open) open--;
        else {
            swaps++;
            open++;
        }
    }
    cout << swaps;
    return 0;
}
