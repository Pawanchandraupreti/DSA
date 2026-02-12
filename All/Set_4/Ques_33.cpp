// Find Last Occurrence of an Element

#include <iostream>
using namespace std;

int main() {
    int arr[] = {1, 2, 2, 2, 3};
    int n = 5, key = 2;

    int l = 0, r = n - 1, ans = -1;

    while (l <= r) {
        int mid = l + (r - l) / 2;

        if (arr[mid] == key) {
            ans = mid;
            l = mid + 1;
        } else if (arr[mid] < key)
            l = mid + 1;
        else
            r = mid - 1;
    }

    cout << ans;
    return 0;
}



