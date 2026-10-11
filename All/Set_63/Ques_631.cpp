// Maximum Subarray Sum

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    int current = 0, answer = INT_MIN;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        current = max(x, current + x);
        answer = max(answer, current);
    }
    cout << answer << '\n';
    return 0;
}
