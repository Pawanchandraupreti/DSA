// Find Minimum Element in Array

#include <iostream>
using namespace std;

int main() {
    int arr[] = {45, 12, 67, 8, 34, 56};
    int n = 6;
    int minVal = arr[0];
    
    for (int i = 1; i < n; i++) {
        if (arr[i] < minVal) {
            minVal = arr[i];
        }
    }
    
    cout << "Minimum element is: " << minVal << endl;
    
    return 0;
}

