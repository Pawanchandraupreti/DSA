// Next Greater Element in Circular Array

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n), answer(n, -1), st;
    for (int &x : a) cin >> x;
    for (int i = 0; i < 2 * n; i++) {
        while (!st.empty() && a[st.back()] < a[i % n]) {
            answer[st.back()] = a[i % n];
            st.pop_back();
        }
        if (i < n) st.push_back(i);
    }
    for (int x : answer) cout << x << ' ';
    cout << '\n';
    return 0;
}
