// Find the Second Largest Element in an Array

#include <iostream>
using namespace std;

int main() {
    int arr[] = {12, 45, 7, 89, 23};
    int n = 5;
    int largest = arr[0];
    int secondLargest = -1;

    for (int i = 1; i < n; i++) {
        if (arr[i] > largest) {
            secondLargest = largest;
            largest = arr[i];
        } else if (arr[i] > secondLargest && arr[i] != largest) {
            secondLargest = arr[i];
        }
    }

    cout << "Second largest element: " << secondLargest << endl;

    return 0;
}