// Check Palindrome Array

#include <iostream>
using namespace std;

int main() {
    int arr[] = {1, 2, 3, 2, 1};
    int n = 5;
    bool isPalindrome = true;

    for (int i = 0; i < n / 2; i++) {
        if (arr[i] != arr[n - 1 - i]) {
            isPalindrome = false;
            break;
        }
    }

    if (isPalindrome) {
        cout << "Array is a palindrome." << endl;
    } else {
        cout << "Array is not a palindrome." << endl;
    }

    return 0;
}
