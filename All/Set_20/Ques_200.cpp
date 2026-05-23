// Find Missing and Repeating Number

#include <iostream>
using namespace std;

int main() {
    int arr[] = {1, 2, 3, 3, 5};
    int n = 5;
    long long sum = 0;
    long long sumSquares = 0;

    for (int i = 0; i < n; i++) {
        sum += arr[i];
        sumSquares += 1LL * arr[i] * arr[i];
    }

    long long expectedSum = 1LL * n * (n + 1) / 2;
    long long expectedSumSquares = 1LL * n * (n + 1) * (2LL * n + 1) / 6;

    long long diff = expectedSum - sum;
    long long squareDiff = expectedSumSquares - sumSquares;

    long long missing = (diff + squareDiff / diff) / 2;
    long long repeating = missing - diff;

    cout << "Missing number: " << missing << endl;
    cout << "Repeating number: " << repeating << endl;

    return 0;
}



