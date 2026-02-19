// Remove Duplicates from Sorted Array (In-place)

#include <iostream>
using namespace std;

int main() {
    int arr[] = {1,1,2,2,3};
    int n = 5;

    int k = 1;

    for (int i = 1; i < n; i++) {
        if (arr[i] != arr[i - 1])
            arr[k++] = arr[i];
    }

    cout << k; 
    return 0;
}
