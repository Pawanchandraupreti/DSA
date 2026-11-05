// Longest Dictionary Word by Deleting Characters

#include <bits/stdc++.h>
using namespace std;

bool canMake(const string &source, const string &word) {
    int i = 0;
    for (char ch : source) if (i < (int)word.size() && ch == word[i]) i++;
    return i == (int)word.size();
}

int main() {
    string source;
    int n;
    cin >> source >> n;
    string answer;
    while (n--) {
        string word;
        cin >> word;
        if (canMake(source, word) && (word.size() > answer.size() || word.size() == answer.size() && word < answer)) answer = word;
    }
    cout << answer << '\n';
    return 0;
}
