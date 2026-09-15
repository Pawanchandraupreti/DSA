// Largest Rectangle in Histogram

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> h(n);
    for (int &x : h) cin >> x;

    stack<int> st;
    int ans = 0;
    for (int i = 0; i <= n; i++) {
        int cur = (i == n) ? 0 : h[i];
        while (!st.empty() && cur < h[st.top()]) {
            int height = h[st.top()];
            st.pop();
            int left = st.empty() ? -1 : st.top();
            ans = max(ans, height * (i - left - 1));
        }
        st.push(i);
    }

    cout << ans << '\n';
    return 0;
}


