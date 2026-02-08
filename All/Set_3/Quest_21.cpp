// Prefix Sum Array

#include <iostream>
using namespace std;

int main() {
    int arr[] = {2, 4, 6, 8};
    int n = 4;
    int prefix[4];

    prefix[0] = arr[0];
    for (int i = 1; i < n; i++)
        prefix[i] = prefix[i - 1] + arr[i];

    for (int i = 0; i < n; i++)
        cout << prefix[i] << " ";

    return 0;
}
