// Check if String is Palindrome

#include <iostream>
using namespace std;

int main() {
    string s = "madam";
    int l = 0, r = s.length() - 1;
    bool ok = true;

    while (l < r) {
        if (s[l] != s[r]) {
            ok = false;
            break;
        }
        l++;
        r--;
    }

    if (ok) cout << "Palindrome";
    else cout << "Not Palindrome";

    return 0;
}
