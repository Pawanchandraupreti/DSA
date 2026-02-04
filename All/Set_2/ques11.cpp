// Move All Zeros to End (order preserved)

#include <iostream>
using namespace std;

int main() {
    int arr[] = {0, 1, 0, 3, 12};
    int n = 5;
    int idx = 0;

    for (int i = 0; i < n; i++) {
        if (arr[i] != 0)
            arr[idx++] = arr[i];
    }

    while (idx < n)
        arr[idx++] = 0;

    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";

    return 0;
}


