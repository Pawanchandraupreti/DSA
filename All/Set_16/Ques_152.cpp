// Find Second Largest Element in Array

#include <iostream>
using namespace std;

int main() {
    int arr[] = {12, 35, 1, 10, 34, 1};
    int n = 6;
    
    int largest = INT_MIN, secondLargest = INT_MIN;
    
    for (int i = 0; i < n; i++) {
        if (arr[i] > largest) {
            secondLargest = largest;
            largest = arr[i];
        } else if (arr[i] > secondLargest && arr[i] != largest) {
            secondLargest = arr[i];
        }
    }
    
    cout << "Largest: " << largest << endl;
    cout << "Second Largest: " << secondLargest << endl;
    
    return 0;
}
