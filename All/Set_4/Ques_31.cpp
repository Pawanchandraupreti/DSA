// Binary Search (Iterative)

#include <iostream>
using namespace std;

int main() {
    int arr[] = {1, 3, 5, 7, 9};
    int n = 5, key = 7;

    int l = 0, r = n - 1;
    bool found = false;

    while (l <= r) {
        int mid = l + (r - l) / 2;

        if (arr[mid] == key) {
            found = true;
            break;
        } else if (arr[mid] < key)
            l = mid + 1;
        else
            r = mid - 1;
    }

    if (found) cout << "Found";
    else cout << "Not Found";

    return 0;
}
