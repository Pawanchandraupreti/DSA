// Find Minimum Element in an Array

#include <iostream>
using namespace std;

int main() {
    int arr[] = {8, 3, 6, 2, 9};
    int n = 5;

    int mn = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] < mn)
            mn = arr[i];
    }

    cout << mn;
    return 0;
}
