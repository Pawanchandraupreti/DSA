// Decode Encoded String

#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    stack<int> counts;
    stack<string> parts;
    string current;
    int number = 0;

    for (char ch : s) {
        if (isdigit(ch)) number = number * 10 + ch - '0';
        else if (ch == '[') {
            counts.push(number);
            parts.push(current);
            number = 0;
            current.clear();
        } else if (ch == ']') {
            string previous = parts.top();
            parts.pop();
            current = previous;
            string repeated = current;
            current.clear();
            for (int i = 0; i < counts.top(); i++) current += repeated;
            counts.pop();
        } else current += ch;
    }
    cout << current << '\n';
    return 0;
}
