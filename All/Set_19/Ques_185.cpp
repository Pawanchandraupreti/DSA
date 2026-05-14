// Check if Array is Sorted

#include <iostream>
using namespace std;

int main() {
    int arr[] = {1, 3, 5, 7, 9, 11};
    int n = 6;
    bool isSorted = true;
    
    for (int i = 0; i < n - 1; i++) {
        if (arr[i] > arr[i + 1]) {
            isSorted = false;
            break;
        }
    }
    
    if (isSorted) {
        cout << "Array is sorted in ascending order" << endl;
    } else {
        cout << "Array is not sorted" << endl;
    }
    
    return 0;
}


