// Binary Search on Answer – Smallest Divisor

#include <iostream>
using namespace std;

int computeSum(int arr[], int n, int divisor) {
    int sum = 0;
    for (int i = 0; i < n; i++)
        sum += (arr[i] + divisor - 1) / divisor;  
    return sum;
}

int main() {
    int arr[] = {1,2,5,9};
    int n = 4, threshold = 6;

    int l = 1, r = 9, ans = r;

    while (l <= r) {
        int mid = l + (r - l) / 2;

        if (computeSum(arr, n, mid) <= threshold) {
            ans = mid;
            r = mid - 1;
        } else
            l = mid + 1;
    }

    cout << ans;
    return 0;
}
