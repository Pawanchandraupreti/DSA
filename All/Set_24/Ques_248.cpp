// Largest rectangle in histogram

#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

int main() {
    int n; if (!(cin >> n)) return 0;
    vector<long long> h(n);
    for (int i = 0; i < n; ++i) cin >> h[i];
    stack<int> st;
    long long best = 0;
    for (int i = 0; i <= n; ++i) {
        long long cur = (i == n) ? 0 : h[i];
        while (!st.empty() && cur < h[st.top()]) {
            long long height = h[st.top()]; st.pop();
            int l = st.empty() ? 0 : st.top() + 1;
            long long area = height * (i - l);
            best = max(best, area);
        }
        st.push(i);
    }
    cout << best;
    return 0;
}


