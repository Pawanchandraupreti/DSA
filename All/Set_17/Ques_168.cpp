// Count Frequency of an Element in Array

#include <iostream>
using namespace std;

int main() {
    int arr[] = {1, 2, 3, 2, 4, 2, 5, 2};
    int n = 8;
    int target = 2;
    int frequency = 0;

    for (int i = 0; i < n; i++) {
        if (arr[i] == target) {
            frequency++;
        }
    }

    cout << "Frequency of " << target << " is: " << frequency << endl;

    return 0;
}


