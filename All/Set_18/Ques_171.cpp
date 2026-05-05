// Find the Second Largest Element in an Array

#include <iostream>
using namespace std;

int main() {
    int arr[] = {12, 35, 1, 10, 34, 1};
    int n = 6;
    int largest = arr[0];
    int secondLargest = -1;

    for (int i = 1; i < n; i++) {
        if (arr[i] > largest) {
            secondLargest = largest;
            largest = arr[i];
        } else if (arr[i] != largest && arr[i] > secondLargest) {
            secondLargest = arr[i];
        }
    }

    cout << "Second largest element: " << secondLargest << endl;

    return 0;
}

