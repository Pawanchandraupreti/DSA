// Longest Turbulent Subarray

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &x : a) cin >> x;
    int up = 1, down = 1, answer = n > 0;
    for (int i = 1; i < n; i++) {
        if (a[i] > a[i - 1]) up = down + 1, down = 1;
        else if (a[i] < a[i - 1]) down = up + 1, up = 1;
        else up = down = 1;
        answer = max(answer, max(up, down));
    }
    cout << answer << '\n';
    return 0;
}
