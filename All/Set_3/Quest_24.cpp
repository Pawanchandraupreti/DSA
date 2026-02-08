// Count Subarrays with Sum = K (Brute Intro)

#include <iostream>
using namespace std;

int main() {
    int arr[] = {1, 2, 3};
    int n = 3, k = 3;
    int count = 0;

    for (int i = 0; i < n; i++) {
        int sum = 0;
        for (int j = i; j < n; j++) {
            sum += arr[j];
            if (sum == k)
                count++;
        }
    }

    cout << count;
    return 0;
}
