// Valid Parentheses

#include <bits/stdc++.h>
using namespace std;

int main() {
    string text;
    cin >> text;
    stack<char> brackets;
    for (char bracket : text) {
        if (bracket == '(' || bracket == '[' || bracket == '{') brackets.push(bracket);
        else {
            if (brackets.empty()) {
                cout << "false\n";
                return 0;
            }
            char open = brackets.top();
            brackets.pop();
            if ((bracket == ')' && open != '(') || (bracket == ']' && open != '[') || (bracket == '}' && open != '{')) {
                cout << "false\n";
                return 0;
            }
        }
    }
    cout << (brackets.empty() ? "true" : "false") << '\n';
    return 0;
}
