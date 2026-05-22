// Find Leaders in Array

#include <iostream>
using namespace std;

int main() {
    int arr[] = {16, 17, 4, 3, 5, 2};
    int n = 6;
    int leaders[6];
    int count = 0;
    int maxFromRight = arr[n - 1];

    leaders[count++] = maxFromRight;

    for (int i = n - 2; i >= 0; i--) {
        if (arr[i] > maxFromRight) {
            maxFromRight = arr[i];
            leaders[count++] = maxFromRight;
        }
    }

    cout << "Leaders in array: ";
    for (int i = count - 1; i >= 0; i--) {
        cout << leaders[i] << " ";
    }
    cout << endl;

    return 0;
}



