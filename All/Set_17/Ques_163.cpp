// Remove Duplicates from Sorted Array

#include <iostream>
using namespace std;

int main() {
    int arr[] = {1, 1, 2, 2, 3, 4, 4, 5};
    int n = 8;
    int index = 1;

    for (int i = 1; i < n; i++) {
        if (arr[i] != arr[index - 1]) {
            arr[index] = arr[i];
            index++;
        }
    }

    cout << "Array after removing duplicates: ";
    for (int i = 0; i < index; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    cout << "New length: " << index << endl;

    return 0;
}

