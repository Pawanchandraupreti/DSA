// Print All Subsequences (Recursion Basics)

#include <iostream>
using namespace std;

void printSubseq(string s, string curr, int index) {
    if (index == s.length()) {
        cout << curr << endl;
        return;
    }

    printSubseq(s, curr + s[index], index + 1);
    printSubseq(s, curr, index + 1);
}

int main() {
    printSubseq("abc", "", 0);
    return 0;
}
