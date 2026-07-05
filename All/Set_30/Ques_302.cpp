// Find the second largest element in an array

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    if (!(cin >> n)) return 0;

    long long largest = LLONG_MIN, secondLargest = LLONG_MIN;
    for (int i = 0; i < n; ++i) {
        long long x;
        cin >> x;
        if (x > largest) {
            secondLargest = largest;
            largest = x;
        } else if (x < largest && x > secondLargest) {
            secondLargest = x;
        }
    }

    if (secondLargest == LLONG_MIN) cout << -1;
    else cout << secondLargest;
    return 0;
}