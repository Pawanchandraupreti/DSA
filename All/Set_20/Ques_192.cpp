// Find Sum of All Array Elements

#include <iostream>
using namespace std;

int main() {
    int arr[] = {5, 10, 15, 20, 25};
    int n = 5;
    int sum = 0;
    
    for (int i = 0; i < n; i++) {
        sum += arr[i];
    }
    
    cout << "Sum of array elements: " << sum << endl;
    
    return 0;
}
