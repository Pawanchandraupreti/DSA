// Find Missing Number in 1 to n

#include <iostream>
using namespace std;

int main() {
    int arr[] = {1, 2, 4, 5, 6};
    int n = 5;
    int total = (n + 1) * (n + 2) / 2;
    int sum = 0;

    for (int i = 0; i < n; i++) {
        sum += arr[i];
    }

    cout << "Missing Number: " << total - sum << endl;

    return 0;
}




