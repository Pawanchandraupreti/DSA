// Find Maximum Element in an Array

#include <iostream>
using namespace std;

int main() {
    int arr[] = {3, 1, 7, 2, 5};
    int n = 5;

    int mx = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > mx)
            mx = arr[i];
    }

    cout << mx;
    return 0;
}
