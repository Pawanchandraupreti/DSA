// Linear Search

#include <iostream>
using namespace std;

int main() {
    int arr[] = {4, 7, 1, 9, 3};
    int n = 5, key = 9;
    bool found = false;

    for (int i = 0; i < n; i++) {
        if (arr[i] == key) {
            found = true;
            break;
        }
    }

    if (found)
        cout << "Found";
    else
        cout << "Not Found";

    return 0;
}
