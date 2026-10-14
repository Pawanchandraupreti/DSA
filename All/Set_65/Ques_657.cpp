// Evaluate Reverse Polish Notation

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<string> tokens(n);
    for (string &token : tokens) cin >> token;
    stack<int> values;

    for (string token : tokens) {
        if (isdigit(token[0]) || (token.size() > 1 && token[0] == '-')) {
            values.push(stoi(token));
            continue;
        }
        int right = values.top(); values.pop();
        int left = values.top(); values.pop();
        if (token == "+") values.push(left + right);
        else if (token == "-") values.push(left - right);
        else if (token == "*") values.push(left * right);
        else values.push(left / right);
    }
    cout << values.top() << '\n';
    return 0;
}
