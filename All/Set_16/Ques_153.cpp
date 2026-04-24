// Sum of All Elements in Array

#include <iostream>
using namespace std;

int main() {
    int arr[] = {10, 20, 30, 40, 50};
    int n = 5;
    int sum = 0;
    
    for (int i = 0; i < n; i++) {
        sum += arr[i];
    }
    
    cout << "Sum of Array: " << sum << endl;
    
    return 0;
}
