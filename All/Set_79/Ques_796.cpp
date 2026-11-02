// Maximum Width Ramp

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n), stack;
    for (int &x : a) cin >> x;
    for (int i = 0; i < n; i++) if (stack.empty() || a[stack.back()] > a[i]) stack.push_back(i);
    int answer = 0;
    for (int i = n - 1; i >= 0; i--) {
        while (!stack.empty() && a[stack.back()] <= a[i]) {
            answer = max(answer, i - stack.back());
            stack.pop_back();
        }
    }
    cout << answer << '\n';
    return 0;
}
