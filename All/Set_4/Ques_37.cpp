// Find Minimum in Rotated Sorted Array

#include <iostream>
using namespace std;

int main() {
    int arr[] = {4,5,6,7,0,1,2};
    int n = 7;

    int l = 0, r = n - 1;

    while (l < r) {
        int mid = l + (r - l) / 2;

        if (arr[mid] > arr[r])
            l = mid + 1;
        else
            r = mid;
    }

    cout << arr[l];
    return 0;
}
