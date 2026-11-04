// Score of Parentheses

#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    stack<int> values;
    values.push(0);
    for (char ch : s) {
        if (ch == '(') values.push(0);
        else {
            int inside = values.top();
            values.pop();
            values.top() += inside ? 2 * inside : 1;
        }
    }
    cout << values.top() << '\n';
    return 0;
}
