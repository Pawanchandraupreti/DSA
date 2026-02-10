// Longest Subarray with Sum ≤ K

#include <iostream>
using namespace std;

int main() {
    int arr[] = {1, 2, 1, 1, 1};
    int n = 5, k = 3;

    int l = 0, sum = 0, maxLen = 0;

    for (int r = 0; r < n; r++) {
        sum += arr[r];

        while (sum > k) {
            sum -= arr[l];
            l++;
        }

        maxLen = max(maxLen, r - l + 1);
    }

    cout << maxLen;
    return 0;
}
