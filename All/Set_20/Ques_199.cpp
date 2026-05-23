// Move Negative Numbers to One Side

#include <iostream>
using namespace std;

int main() {
    int arr[] = {12, -7, 5, -3, 8, -1, 4};
    int n = 7;
    int left = 0;
    int right = n - 1;

    while (left <= right) {
        if (arr[left] < 0) {
            left++;
        } else if (arr[right] >= 0) {
            right--;
        } else {
            int temp = arr[left];
            arr[left] = arr[right];
            arr[right] = temp;
            left++;
            right--;
        }
    }

    cout << "Array after moving negatives: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
