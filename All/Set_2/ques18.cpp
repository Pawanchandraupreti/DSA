// Find Intersection of Two Sorted Arrays

#include <iostream>
using namespace std;

int main() {
    int a[] = {1, 2, 2, 3, 4};
    int b[] = {2, 2, 4, 6};
    int n = 5, m = 4;

    int i = 0, j = 0;
    while (i < n && j < m) {
        if (a[i] < b[j])
            i++;
        else if (a[i] > b[j])
            j++;
        else {
            cout << a[i] << " ";
            i++; j++;
        }
    }

    return 0;
}

