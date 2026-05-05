// Count the Frequency of Each Element in an Array

#include <iostream>
using namespace std;

int main() {
    int arr[] = {2, 3, 2, 2, 4, 3, 5};
    int n = 7;
    bool visited[7] = {false};

    for (int i = 0; i < n; i++) {
        if (visited[i]) {
            continue;
        }

        int count = 1;
        for (int j = i + 1; j < n; j++) {
            if (arr[i] == arr[j]) {
                count++;
                visited[j] = true;
            }
        }

        cout << arr[i] << " occurs " << count << " time(s)" << endl;
    }

    return 0;
}

