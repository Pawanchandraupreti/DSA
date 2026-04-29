// Find Maximum and Minimum in Array

#include <iostream>
#include <climits>
using namespace std;

int main() {
    int arr[] = {45, 12, 78, 3, 56, 19};
    int n = 6;

    int maximum = INT_MIN;
    int minimum = INT_MAX;

    for (int i = 0; i < n; i++) {
        if (arr[i] > maximum) {
            maximum = arr[i];
        }
        if (arr[i] < minimum) {
            minimum = arr[i];
        }
    }

    cout << "Maximum Element: " << maximum << endl;
    cout << "Minimum Element: " << minimum << endl;

    return 0;
}
