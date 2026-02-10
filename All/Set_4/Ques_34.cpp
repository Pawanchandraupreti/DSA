// Count Occurrences in Sorted Array

#include <iostream>
using namespace std;

#include <iostream>
using namespace std;

int firstOccurrence(int arr[], int n, int key) {
    int l = 0, r = n - 1, ans = -1;

    while (l <= r) {
        int mid = l + (r - l) / 2;

        if (arr[mid] == key) {
            ans = mid;
            r = mid - 1;
        } else if (arr[mid] < key)
            l = mid + 1;
        else
            r = mid - 1;
    }
    return ans;
}

int lastOccurrence(int arr[], int n, int key) {
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
    return ans;
}

int main() {
    int arr[] = {1, 2, 2, 2, 3, 4};
    int n = 6, key = 2;

    int first = firstOccurrence(arr, n, key);
    int last = lastOccurrence(arr, n, key);

    if (first == -1)
        cout << 0;
    else
        cout << last - first + 1;

    return 0;
}

