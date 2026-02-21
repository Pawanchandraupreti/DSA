// Minimum Window Size with Sum ≥ K

#include <iostream>
using namespace std;

int main() {
    int arr[] = {2,3,1,2,4,3};
    int n = 6, k = 7;

    int l = 0, sum = 0, minLen = 1e9;

    for (int r = 0; r < n; r++) {
        sum += arr[r];

        while (sum >= k) {
            minLen = min(minLen, r - l + 1);
            sum -= arr[l];
            l++;
        }
    }

    if (minLen == 1e9) cout << 0;
    else cout << minLen;

    return 0;
}