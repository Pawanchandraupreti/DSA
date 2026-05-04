// Check Whether Two Arrays are Equal

#include <iostream>
using namespace std;

int main() {
    int arr1[] = {1, 2, 3, 4};
    int arr2[] = {1, 2, 3, 4};
    int n = 4;
    bool areEqual = true;

    for (int i = 0; i < n; i++) {
        if (arr1[i] != arr2[i]) {
            areEqual = false;
            break;
        }
    }

    if (areEqual) {
        cout << "Both arrays are equal." << endl;
    } else {
        cout << "Arrays are not equal." << endl;
    }

    return 0;
}