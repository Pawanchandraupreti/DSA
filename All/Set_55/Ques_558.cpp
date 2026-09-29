// Evaluate Postfix Expression

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    stack<int> values;
    for (int i = 0; i < n; i++) {
        string token;
        cin >> token;
        if (isdigit(token[0])) values.push(stoi(token));
        else {
            int right = values.top(); values.pop();
            int left = values.top(); values.pop();
            if (token == "+") values.push(left + right);
            else if (token == "-") values.push(left - right);
            else if (token == "*") values.push(left * right);
            else values.push(left / right);
        }
    }
    cout << values.top() << '\n';
    return 0;
}
