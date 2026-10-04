// Ransom Note

#include <bits/stdc++.h>
using namespace std;

int main() {
    string note, magazine;
    cin >> note >> magazine;
    vector<int> frequency(256);
    for (char letter : magazine) frequency[(unsigned char)letter]++;
    for (char letter : note) {
        if (--frequency[(unsigned char)letter] < 0) {
            cout << "false\n";
            return 0;
        }
    }
    cout << "true\n";
    return 0;
}


