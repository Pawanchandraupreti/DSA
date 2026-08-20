// Check whether an array is a palindrome

#include <bits/stdc++.h>
using namespace std;

bool isPalindrome(const vector<int>& arr) {
    int left = 0;
    int right = (int)arr.size() - 1;

    while (left < right) {
        if (arr[left] != arr[right]) {
            return false;
        }
        ++left;
        --right;
    }

    return true;
}

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    cout << (isPalindrome(arr) ? 1 : 0);
    return 0;
}


