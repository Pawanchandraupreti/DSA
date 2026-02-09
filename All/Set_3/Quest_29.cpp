// Longest Subarray with Sum = K

#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
    int arr[] = {10, 5, 2, 7, 1, 9};
    int n = 6, k = 15;

    unordered_map<int, int> mp;
    int sum = 0, maxLen = 0;

    for (int i = 0; i < n; i++) {
        sum += arr[i];

        if (sum == k)
            maxLen = i + 1;

        if (!mp.count(sum))
            mp[sum] = i;

        if (mp.count(sum - k))
            maxLen = max(maxLen, i - mp[sum - k]);
    }

    cout << maxLen;
    return 0;
}
