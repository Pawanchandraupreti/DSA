// Sort Colors Using Dutch National Flag Algorithm

#include <iostream>
using namespace std;

int main() {
    int arr[] = {2, 0, 2, 1, 1, 0, 2, 1, 0};
    int n = 9;
    int low = 0, mid = 0, high = n - 1;

    while (mid <= high) {
        if (arr[mid] == 0) {
            int temp = arr[low];
            arr[low] = arr[mid];
            arr[mid] = temp;
            low++;
            mid++;
        } else if (arr[mid] == 1) {
            mid++;
        } else {
            int temp = arr[mid];
            arr[mid] = arr[high];
            arr[high] = temp;
            high--;
        }
    }

    cout << "Array after sorting colors: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
