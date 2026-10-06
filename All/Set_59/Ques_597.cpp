// Backspace String Compare

#include <bits/stdc++.h>
using namespace std;

string clean(string text) {
    string answer;
    for (char letter : text) {
        if (letter == '#') {
            if (!answer.empty()) answer.pop_back();
        } else answer.push_back(letter);
    }
    return answer;
}

int main() {
    string first, second;
    cin >> first >> second;
    cout << (clean(first) == clean(second) ? "true" : "false") << '\n';
    return 0;
}


