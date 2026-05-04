// Find the Missing Number from 1 to N

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

    cout << "Missing number: " << total - sum << endl;

    return 0;
}