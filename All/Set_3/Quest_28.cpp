// Subarray with Sum = K (Optimized – Hashing)

#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
    int arr[] = {1, 2, 3};
    int n = 3, k = 3;

    unordered_map<int, int> mp;
    mp[0] = 1;

    int sum = 0, count = 0;

    for (int i = 0; i < n; i++) {
        sum += arr[i];

        if (mp.count(sum - k))
            count += mp[sum - k];

        mp[sum]++;
    }

    cout << count;
    return 0;
}
