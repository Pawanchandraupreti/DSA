// Next Greater Element on the Right

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n), ans(n, -1), st;
    for (int &v : a) cin >> v;

    for (int i = n - 1; i >= 0; i--) {
        while (!st.empty() && st.back() <= a[i]) st.pop_back();
        if (!st.empty()) ans[i] = st.back();
        st.push_back(a[i]);
    }

    for (int v : ans) cout << v << ' ';
    cout << '\n';
    return 0;
}
