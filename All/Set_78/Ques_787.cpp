// Minimum Cost Tree from Leaf Values

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n), st;
    for (int &x : a) cin >> x;
    int answer = 0;
    for (int x : a) {
        while (!st.empty() && st.back() <= x) {
            int middle = st.back();
            st.pop_back();
            answer += middle * min(st.empty() ? x : st.back(), x);
        }
        st.push_back(x);
    }
    while (st.size() > 1) {
        int middle = st.back();
        st.pop_back();
        answer += middle * st.back();
    }
    cout << answer << '\n';
    return 0;
}
