// Daily Temperatures

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> t(n), ans(n), st;
    for (int &x : t) cin >> x;

    for (int i = 0; i < n; i++) {
        while (!st.empty() && t[i] > t[st.back()]) {
            int j = st.back();
            st.pop_back();
            ans[j] = i - j;
        }
        st.push_back(i);
    }

    for (int x : ans) cout << x << ' ';
    cout << '\n';
    return 0;
}

