// Check Balanced Brackets

#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    stack<char> st;
    bool ok = true;
    for (char c : s) {
        if (c == '(' || c == '[' || c == '{') {
            st.push(c);
        } else {
            if (st.empty()) {
                ok = false;
                break;
            }
            char open = st.top();
            st.pop();
            if ((c == ')' && open != '(') ||
                (c == ']' && open != '[') ||
                (c == '}' && open != '{')) {
                ok = false;
                break;
            }
        }
    }
    if (!st.empty()) ok = false;
    cout << (ok ? "YES\n" : "NO\n");
    return 0;
}

