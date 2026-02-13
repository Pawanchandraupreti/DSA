// Find Position to Insert (Lower Bound)

#include <iostream>
using namespace std;

int main() {
    int arr[] = {1,3,5,6};
    int n = 4, target = 2;

    int l = 0, r = n - 1;

    while (l <= r) {
        int mid = l + (r - l) / 2;

        if (arr[mid] < target)
            l = mid + 1;
        else
            r = mid - 1;
    }

    cout << l;
    return 0;
}
