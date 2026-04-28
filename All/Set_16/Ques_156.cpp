// Find Maximum Element in Array

#include <iostream>
using namespace std;

int main() {
    int arr[] = {8, 21, 4, 19, 33, 10};
    int n = 6;
    int maximum = arr[0];

    for (int i = 1; i < n; i++) {
        if (arr[i] > maximum) {
            maximum = arr[i];
        }
    }

    cout << "Maximum Element: " << maximum << endl;

    return 0;
}

