// Count Occurrences of an Element in Array

#include <iostream>
using namespace std;

int main() {
    int arr[] = {5, 3, 5, 2, 5, 7, 8, 5};
    int n = 8;
    int target = 5;
    int count = 0;

    for (int i = 0; i < n; i++) {
        if (arr[i] == target) {
            count++;
        }
    }

    cout << "Element " << target << " occurs " << count << " times" << endl;

    return 0;
}
