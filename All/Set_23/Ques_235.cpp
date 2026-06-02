// Reverse string

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    string s; if (!(cin >> s)) return 0;
    reverse(s.begin(), s.end());
    cout << s;
    return 0;
}
