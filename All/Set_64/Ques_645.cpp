// Daily Temperatures

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> temperature(n), answer(n), st;
    for (int &x : temperature) cin >> x;

    for (int i = 0; i < n; i++) {
        while (!st.empty() && temperature[i] > temperature[st.back()]) {
            answer[st.back()] = i - st.back();
            st.pop_back();
        }
        st.push_back(i);
    }
    for (int x : answer) cout << x << ' ';
    cout << '\n';
    return 0;
}
