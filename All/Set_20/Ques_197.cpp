// Find Maximum Consecutive Ones

#include <iostream>
using namespace std;

int main() {
    int arr[] = {1, 1, 0, 1, 1, 1, 0, 1};
    int n = 8;
    int currentCount = 0;
    int maxCount = 0;

    for (int i = 0; i < n; i++) {
        if (arr[i] == 1) {
            currentCount++;
            if (currentCount > maxCount) {
                maxCount = currentCount;
            }
        } else {
            currentCount = 0;
        }
    }

    cout << "Maximum consecutive ones: " << maxCount << endl;

    return 0;
}

