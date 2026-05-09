// Remove Duplicates from Sorted Array

#include <iostream>
using namespace std;

int main() {
    int arr[] = {1, 1, 2, 2, 2, 3, 4, 4, 5};
    int n = 9;
    int uniqueCount = 1;
    
    for (int i = 1; i < n; i++) {
        if (arr[i] != arr[i - 1]) {
            arr[uniqueCount] = arr[i];
            uniqueCount++;
        }
    }
    
    cout << "Array after removing duplicates: ";
    for (int i = 0; i < uniqueCount; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    cout << "New length: " << uniqueCount << endl;
    
    return 0;
}
