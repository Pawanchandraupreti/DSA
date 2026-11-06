// Maximum Subarray Min Product

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<long long> a(n), prefix(n + 1);
    for (int i = 0; i < n; i++) { cin >> a[i]; prefix[i + 1] = prefix[i] + a[i]; }
    vector<int> st;
    long long answer = 0;
    for (int i = 0; i <= n; i++) {
        long long value = i == n ? 0 : a[i];
        while (!st.empty() && a[st.back()] > value) {
            int middle = st.back(); st.pop_back();
            int left = st.empty() ? 0 : st.back() + 1;
            answer = max(answer, a[middle] * (prefix[i] - prefix[left]));
        }
        st.push_back(i);
    }
    cout << answer << '\n';
    return 0;
}
