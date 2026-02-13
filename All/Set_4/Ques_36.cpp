// Search in Rotated Sorted Array

#include <iostream>
using namespace std;

int main() {
    int arr[] = {4,5,6,7,0,1,2};
    int n = 7, target = 0;

    int l = 0, r = n - 1;
    int ans = -1;

    while (l <= r) {
        int mid = l + (r - l) / 2;

        if (arr[mid] == target) {
            ans = mid;
            break;
        }

        if (arr[l] <= arr[mid]) {  
            if (arr[l] <= target && target < arr[mid])
                r = mid - 1;
            else
                l = mid + 1;
        } else {  
            if (arr[mid] < target && target <= arr[r])
                l = mid + 1;
            else
                r = mid - 1;
        }
    }

    cout << ans;
    return 0;
}
