// Longest Valid Parentheses

#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    stack<int> st;
    st.push(-1);
    int answer = 0;
    for (int i = 0; i < (int)s.size(); i++) {
        if (s[i] == '(') st.push(i);
        else {
            st.pop();
            if (st.empty()) st.push(i);
            else answer = max(answer, i - st.top());
        }
    }
    cout << answer << '\n';
    return 0;
}

