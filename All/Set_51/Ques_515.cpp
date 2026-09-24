// Evaluate Reverse Polish Notation

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<long long> st;
    for (int i = 0; i < n; i++) {
        string token;
        cin >> token;
        if (isdigit(token[0]) || (token.size() > 1 && token[0] == '-')) {
            st.push_back(stoll(token));
        } else {
            long long b = st.back(); st.pop_back();
            long long a = st.back(); st.pop_back();
            if (token == "+") st.push_back(a + b);
            else if (token == "-") st.push_back(a - b);
            else if (token == "*") st.push_back(a * b);
            else st.push_back(a / b);
        }
    }

    cout << st.back() << '\n';
    return 0;
}
