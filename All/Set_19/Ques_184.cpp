// Rotate Array to the Right

#include <iostream>
using namespace std;

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int n = 5;
    int k = 2;  // Rotate by 2 positions
    
    k = k % n;  // Handle k > n
    
    int temp[5];
    
    // Store last k elements
    for (int i = 0; i < k; i++) {
        temp[i] = arr[n - k + i];
    }
    
    // Shift remaining elements
    for (int i = n - 1; i >= k; i--) {
        arr[i] = arr[i - k];
    }
    
    // Copy back temp elements
    for (int i = 0; i < k; i++) {
        arr[i] = temp[i];
    }
    
    cout << "Array after rotating by " << k << " positions: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    
    return 0;
}
