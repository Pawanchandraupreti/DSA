// Valid Parentheses

#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    stack<char> st;
    bool valid = true;

    for (char ch : s) {
        if (ch == '(' || ch == '[' || ch == '{') st.push(ch);
        else {
            if (st.empty()) {
                valid = false;
                break;
            }
            char open = st.top();
            st.pop();
            if ((ch == ')' && open != '(') ||
                (ch == ']' && open != '[') ||
                (ch == '}' && open != '{')) {
                valid = false;
                break;
            }
        }
    }

    cout << (valid && st.empty() ? "YES" : "NO") << '\n';
    return 0;
}
