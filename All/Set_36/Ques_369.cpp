// Evaluate a postfix expression with single-digit operands

#include <bits/stdc++.h>
using namespace std;

int evaluatePostfix(const string& expression) {
    stack<int> values;

    for (char token : expression) {
        if (isdigit(token)) {
            values.push(token - '0');
        } else {
            int right = values.top();
            values.pop();
            int left = values.top();
            values.pop();

            if (token == '+') values.push(left + right);
            else if (token == '-') values.push(left - right);
            else if (token == '*') values.push(left * right);
            else if (token == '/') values.push(left / right);
        }
    }

    return values.top();
}

int main() {
    string expression;
    cin >> expression;

    cout << evaluatePostfix(expression);
    return 0;
}
