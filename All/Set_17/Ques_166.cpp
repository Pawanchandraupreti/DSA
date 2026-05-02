// Linear Search in Array

#include <iostream>
using namespace std;

int main() {
    int arr[] = {5, 12, 7, 19, 3, 11};
    int n = 6;
    int target = 19;
    int index = -1;

    for (int i = 0; i < n; i++) {
        if (arr[i] == target) {
            index = i;
            break;
        }
    }

    if (index != -1) {
        cout << "Element found at index: " << index << endl;
    } else {
        cout << "Element not found." << endl;
    }

    return 0;
}


