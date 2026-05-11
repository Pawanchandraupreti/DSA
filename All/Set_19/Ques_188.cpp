// Find Pivot Index in Array

#include <iostream>
using namespace std;

int main() {
    int arr[] = {1, 7, 3, 6, 5, 6};
    int n = 6;
    int totalSum = 0;

    for (int i = 0; i < n; i++) {
        totalSum += arr[i];
    }

    int leftSum = 0;
    int pivotIndex = -1;

    for (int i = 0; i < n; i++) {
        int rightSum = totalSum - leftSum - arr[i];
        if (leftSum == rightSum) {
            pivotIndex = i;
            break;
        }
        leftSum += arr[i];
    }

    if (pivotIndex != -1) {
        cout << "Pivot index: " << pivotIndex << endl;
    } else {
        cout << "No pivot index found" << endl;
    }

    return 0;
}
