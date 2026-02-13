// Find Peak Element

#include <iostream>
using namespace std;

int main() {
    int arr[] = {1, 2, 3, 1};
    int n = 4;

    int l = 0, r = n - 1;

    while (l < r) {
        int mid = l + (r - l) / 2;

        if (arr[mid] < arr[mid + 1])
            l = mid + 1;
        else
            r = mid;
    }

    cout << l;   // peak index
    return 0;
}
