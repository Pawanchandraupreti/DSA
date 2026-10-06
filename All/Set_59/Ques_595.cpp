// Integer Square Root

#include <bits/stdc++.h>
using namespace std;

int main() {
    long long number;
    cin >> number;
    long long left = 0, right = number, answer = 0;
    while (left <= right) {
        long long middle = left + (right - left) / 2;
        if (middle <= number / max(1LL, middle)) {
            answer = middle;
            left = middle + 1;
        } else right = middle - 1;
    }
    cout << answer << '\n';
    return 0;
}


