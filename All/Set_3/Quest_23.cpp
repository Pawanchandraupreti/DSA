// Maximum Sum Subarray of Size K (Sliding Window)

#include <iostream>
using namespace std;

int main() {
    int arr[] = {2, 1, 5, 1, 3, 2};
    int n = 6, k = 3;

    int sum = 0;
    for (int i = 0; i < k; i++)
        sum += arr[i];

    int maxSum = sum;

    for (int i = k; i < n; i++) {
        sum += arr[i] - arr[i - k];
        maxSum = max(maxSum, sum);
    }

    cout << maxSum;
    return 0;
}
