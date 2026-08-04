// Find the largest word in a sentence

#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    getline(cin, s);

    string word, largest;
    stringstream ss(s);
    while (ss >> word) {
        if (word.size() > largest.size()) largest = word;
    }

    cout << largest;
    return 0;
}
