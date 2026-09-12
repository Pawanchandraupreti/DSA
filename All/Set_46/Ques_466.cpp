// Daily Temperatures

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n), ans(n), st;
    for (int& x : a) cin >> x;

    for (int i = 0; i < n; i++) {
        while (!st.empty() && a[st.back()] < a[i]) {
            ans[st.back()] = i - st.back();
            st.pop_back();
        }
        st.push_back(i);
    }
    for (int x : ans) cout << x << ' ';
    return 0;
}
