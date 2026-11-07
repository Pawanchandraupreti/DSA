// Longest Subarray with Positive Product

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    int positive = 0, negative = 0, answer = 0;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if (x == 0) positive = negative = 0;
        else if (x > 0) positive++, negative = negative ? negative + 1 : 0;
        else {
            int oldPositive = positive;
            positive = negative ? negative + 1 : 0;
            negative = oldPositive + 1;
        }
        answer = max(answer, positive);
    }
    cout << answer << '\n';
    return 0;
}
