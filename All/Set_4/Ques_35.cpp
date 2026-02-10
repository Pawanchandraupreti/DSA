// Find Square Root (Binary Search)

#include <iostream>
using namespace std;

int main() {
    int x = 25;
    int l = 0, r = x, ans = 0;

    while (l <= r) {
        int mid = l + (r - l) / 2;

        if (mid * mid <= x) {
            ans = mid;
            l = mid + 1;
        } else
            r = mid - 1;
    }
    cout << ans;
    return 0;
}
