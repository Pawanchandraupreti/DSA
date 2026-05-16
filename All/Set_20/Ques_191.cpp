// Find Maximum Element in Array

#include <iostream>
using namespace std;

int main() {
    int arr[] = {15, 23, 8, 42, 16, 4};
    int n = 6;
    int maxVal = arr[0];
    
    for (int i = 1; i < n; i++) {
        if (arr[i] > maxVal) {
            maxVal = arr[i];
        }
    }
    
    cout << "Maximum element is: " << maxVal << endl;
    
    return 0;
}
