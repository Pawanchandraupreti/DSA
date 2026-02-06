// Find First Non-Repeating Element

#include <iostream>
using namespace std;

int main() {
    int arr[] = {4, 5, 1, 2, 1, 4};
    int n = 6;

    for (int i = 0; i < n; i++) {
        bool repeat = false;
        for (int j = 0; j < n; j++) {
            if (i != j && arr[i] == arr[j]) {
                repeat = true;
                break;
            }
        }
        if (!repeat) {
            cout << arr[i];
            break;
        }
    }

    return 0;
}
