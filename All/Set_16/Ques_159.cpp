// Find Missing Number in Array

#include <iostream>
using namespace std;

int main() {
    int arr[] = {1, 2, 4, 5, 6};
    int n = 5;

    int expectedSum = (n + 1) * (n + 2) / 2;
    int actualSum = 0;

    for (int i = 0; i < n; i++) {
        actualSum += arr[i];
    }

    cout << "Missing Number: " << expectedSum - actualSum << endl;

    return 0;
}