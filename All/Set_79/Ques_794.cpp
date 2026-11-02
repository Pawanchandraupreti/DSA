// Sum of Subarray Minimums

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n), st;
    for (int &x : a) cin >> x;
    const long long mod = 1000000007;
    long long answer = 0;
    for (int i = 0; i <= n; i++) {
        int value = i == n ? INT_MIN : a[i];
        while (!st.empty() && a[st.back()] > value) {
            int middle = st.back();
            st.pop_back();
            int left = st.empty() ? -1 : st.back();
            answer = (answer + 1LL * a[middle] * (middle - left) * (i - middle)) % mod;
        }
        st.push_back(i);
    }
    cout << answer << '\n';
    return 0;
}
