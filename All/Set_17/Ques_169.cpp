// Merge Two Sorted Arrays

#include <iostream>
using namespace std;

int main() {
    int arr1[] = {1, 3, 5, 7};
    int arr2[] = {2, 4, 6, 8};
    int n1 = 4;
    int n2 = 4;
    int merged[8];

    int i = 0, j = 0, k = 0;

    while (i < n1 && j < n2) {
        if (arr1[i] < arr2[j]) {
            merged[k++] = arr1[i++];
        } else {
            merged[k++] = arr2[j++];
        }
    }

    while (i < n1) {
        merged[k++] = arr1[i++];
    }

    while (j < n2) {
        merged[k++] = arr2[j++];
    }

    cout << "Merged Array: ";
    for (int m = 0; m < n1 + n2; m++) {
        cout << merged[m] << " ";
    }
    cout << endl;

    return 0;
}


