// Longest Valid Parentheses

#include <bits/stdc++.h>
using namespace std;

int longestValidParentheses(const string& expression) {
    stack<int> boundaries;
    boundaries.push(-1);
    int longest = 0;

    for (int position = 0; position < (int)expression.size(); ++position) {
        if (expression[position] == '(') {
            boundaries.push(position);
        } else {
            boundaries.pop();
            if (boundaries.empty()) {
                boundaries.push(position);
            } else {
                longest = max(longest, position - boundaries.top());
            }
        }
    }

    return longest;
}

int main() {
    string expression;
    cin >> expression;

    cout << longestValidParentheses(expression);
    return 0;
}


