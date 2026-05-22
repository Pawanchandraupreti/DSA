// Find Single Number Using XOR

#include <iostream>
using namespace std;

int main() {
    int arr[] = {4, 1, 2, 1, 2};
    int n = 5;
    int uniqueValue = 0;

    for (int i = 0; i < n; i++) {
        uniqueValue ^= arr[i];
    }

    cout << "Single number: " << uniqueValue << endl;

    return 0;
}



