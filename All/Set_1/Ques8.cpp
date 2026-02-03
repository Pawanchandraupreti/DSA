// Remove Duplicates from Sorted Array (count unique)

#include <iostream>
using namespace std;

int main() {
    int arr[] = {1, 1, 2, 2, 3};
    int n = 5;

    int uniqueCount = 1;
    for (int i = 1; i < n; i++) {
        if (arr[i] != arr[i - 1])
            uniqueCount++;
    }

    cout << uniqueCount;
    return 0;
}
