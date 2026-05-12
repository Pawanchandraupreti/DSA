// Move All Zeroes to the End

#include <iostream>
using namespace std;

int main() {
    int arr[] = {0, 1, 0, 3, 12, 0, 5};
    int n = 7;
    int index = 0;

    for (int i = 0; i < n; i++) {
        if (arr[i] != 0) {
            arr[index] = arr[i];
            index++;
        }
    }

    while (index < n) {
        arr[index] = 0;
        index++;
    }

    cout << "Array after moving zeroes: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}



