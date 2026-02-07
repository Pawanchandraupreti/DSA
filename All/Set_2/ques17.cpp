// Find Union of Two Sorted Arrays

#include <iostream>
using namespace std;

int main() {
    int a[] = {1, 2, 4, 5};
    int b[] = {2, 3, 5, 6};
    int n = 4, m = 4;

    int i = 0, j = 0;
    while (i < n && j < m) {
        if (a[i] < b[j])
            cout << a[i++] << " ";
        else if (a[i] > b[j])
            cout << b[j++] << " ";
        else {
            cout << a[i] << " ";
            i++; j++;
        }
    }

    while (i < n) cout << a[i++] << " ";
    while (j < m) cout << b[j++] << " ";

    return 0;
}


