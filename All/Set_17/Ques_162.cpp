// Check if Array is Sorted

#include <iostream>
using namespace std;

int main() {
    int arr[] = {2, 4, 7, 9, 15, 21};
    int n = 6;
    bool sorted = true;

    for (int i = 1; i < n; i++) {
        if (arr[i] < arr[i - 1]) {
            sorted = false;
            break;
        }
    }

    if (sorted) {
        cout << "Array is sorted in non-decreasing order." << endl;
    } else {
        cout << "Array is not sorted." << endl;
    }

    return 0;
}


