// Evaluate Postfix Expression (Stack)

#include <iostream>
#include <stack>
using namespace std;

int main() {
    string s = "231*+9-";
    stack<int> st;

    for (char c : s) {
        if (isdigit(c))
            st.push(c - '0');
        else {
            int b = st.top(); st.pop();
            int a = st.top(); st.pop();
            if (c == '+') st.push(a + b);
            if (c == '-') st.push(a - b);
            if (c == '*') st.push(a * b);
            if (c == '/') st.push(a / b);
        }
    }
    cout << st.top();
    return 0;
}


