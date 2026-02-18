// Majority Element (Boyer-Moore Voting)

#include <iostream>
using namespace std;

int main() {
    int arr[] = {2,2,1,1,1,2,2};
    int n = 7;

    int candidate = arr[0], count = 1;

    for (int i = 1; i < n; i++) {
        if (arr[i] == candidate)
            count++;
        else
            count--;

        if (count == 0) {
            candidate = arr[i];
            count = 1;
        }
    }

    cout << candidate;
    return 0;
}