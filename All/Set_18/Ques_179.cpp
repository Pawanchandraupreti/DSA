// Rotate an Array by K Positions

#include <iostream>
using namespace std;

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int n = 5;
    int k = 2;
    int rotated[5];

    k = k % n;

    for (int i = 0; i < n; i++) {
        rotated[(i + k) % n] = arr[i];
    }

    cout << "Rotated array: ";
    for (int i = 0; i < n; i++) {
        cout << rotated[i] << " ";
    }
    cout << endl;

    return 0;
}


