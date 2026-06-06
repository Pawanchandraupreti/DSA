// Count vowels in a string

#include <iostream>
#include <string>
using namespace std;

int main() {
    string s; if (!getline(cin, s)) return 0;
    if (s.empty()) return 0;
    int cnt = 0;
    for (char c : s) {
        char lc = tolower(c);
        if (lc=='a' || lc=='e' || lc=='i' || lc=='o' || lc=='u') ++cnt;
    }
    cout << cnt;
    return 0;
}


