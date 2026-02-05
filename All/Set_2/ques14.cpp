// Find Frequency of Each Element

#include <iostream>
using namespace std;

int main() {
    int arr[] = {1, 2, 2, 3, 1};
    int n = 5;
    bool visited[5] = {false};

    for (int i = 0; i < n; i++) {
        if (visited[i]) continue;

        int count = 1;
        for (int j = i + 1; j < n; j++) {
            if (arr[i] == arr[j]) {
                count++;
                visited[j] = true;
            }
        }
        cout << arr[i] << " -> " << count << endl;
    }

    return 0;
}
