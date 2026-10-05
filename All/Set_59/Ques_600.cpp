// Maximum Product Subarray

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    long long maximum = 0, minimum = 0, answer = LLONG_MIN;
    for (int i = 0; i < n; i++) {
        long long value;
        cin >> value;
        if (i == 0) maximum = minimum = value;
        else {
            long long currentMaximum = max({value, maximum * value, minimum * value});
            minimum = min({value, maximum * value, minimum * value});
            maximum = currentMaximum;
        }
        answer = max(answer, maximum);
    }
    cout << answer << '\n';
    return 0;
}
