//Write a C++ program to find the largest element in an array.

#include <iostream>
using namespace std;

int main() {
    int n = 5;
    int arr[5];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    int max = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > max)
            max = arr[i];
    cout << max;
    return 0;
}
