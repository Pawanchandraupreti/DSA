// Find Minimum in Rotated Sorted Array

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> numbers(n);
    for (int &value : numbers) cin >> value;
    int left = 0, right = n - 1;
    while (left < right) {
        int middle = left + (right - left) / 2;
        if (numbers[middle] > numbers[right]) left = middle + 1;
        else right = middle;
    }
    cout << numbers[left] << '\n';
    return 0;
}


