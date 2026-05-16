// Find Average of Array Elements

#include <iostream>
using namespace std;

int main() {
    int arr[] = {10, 20, 30, 40, 50};
    int n = 5;
    int sum = 0;
    
    for (int i = 0; i < n; i++) {
        sum += arr[i];
    }
    
    double average = (double)sum / n;
    cout << "Average of array elements: " << average << endl;
    
    return 0;
}
