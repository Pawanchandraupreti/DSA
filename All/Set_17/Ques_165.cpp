// Maximum Subarray Sum using Kadane's Algorithm

#include <iostream>
#include <climits>
using namespace std;

int main() {
    int arr[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    int n = 9;

    int currentSum = 0;
    int maximumSum = INT_MIN;

    for (int i = 0; i < n; i++) {
        currentSum += arr[i];
        if (currentSum > maximumSum) {
            maximumSum = currentSum;
        }
        if (currentSum < 0) {
            currentSum = 0;
        }
    }

    cout << "Maximum Subarray Sum: " << maximumSum << endl;

    return 0;
}


