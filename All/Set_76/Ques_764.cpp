// Basic Calculator

#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    getline(cin >> ws, s);
    long long result = 0, number = 0, sign = 1;
    stack<long long> values;
    for (char ch : s) {
        if (isdigit(ch)) number = number * 10 + ch - '0';
        else if (ch == '+' || ch == '-') {
            result += sign * number;
            number = 0;
            sign = ch == '+' ? 1 : -1;
        } else if (ch == '(') {
            values.push(result);
            values.push(sign);
            result = 0;
            sign = 1;
        } else if (ch == ')') {
            result += sign * number;
            number = 0;
            result *= values.top(); values.pop();
            result += values.top(); values.pop();
        }
    }
    cout << result + sign * number << '\n';
    return 0;
}


