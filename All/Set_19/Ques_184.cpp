// Rotate Array to the Right

#include <iostream>
using namespace std;

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int n = 5;
    int k = 2;  
    
    k = k % n;  
    
    int temp[5];
    
    for (int i = 0; i < k; i++) {
        temp[i] = arr[n - k + i];
    }
    
    for (int i = n - 1; i >= k; i--) {
        arr[i] = arr[i - k];
    }
    
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