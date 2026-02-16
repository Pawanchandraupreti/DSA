// Rearrange Array by Sign (Equal Pos/Neg)

#include <iostream>
using namespace std;

int main() {
    int arr[] = {3,1,-2,-5,2,-4};
    int n = 6;

    int result[6];
    int pos = 0, neg = 1;

    for (int i = 0; i < n; i++) {
        if (arr[i] > 0) {
            result[pos] = arr[i];
            pos += 2;
        } else {
            result[neg] = arr[i];
            neg += 2;
        }
    }

    for (int i = 0; i < n; i++)
        cout << result[i] << " ";

    return 0;
}


