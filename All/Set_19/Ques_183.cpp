// Find Missing Number in Array

#include <iostream>
using namespace std;

int main() {
    int arr[] = {1, 2, 3, 5, 6, 7, 8};
    int n = 7;
    int expectedSum = (8 * 9) / 2;  
    int actualSum = 0;
    
    for (int i = 0; i < n; i++) {
        actualSum += arr[i];
    }
    
    int missingNumber = expectedSum - actualSum;
    
    cout << "Missing number: " << missingNumber << endl;
    
    return 0;
}


