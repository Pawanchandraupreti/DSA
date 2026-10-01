// Binary Search

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, target;
    cin >> n >> target;
    vector<int> numbers(n);
    for (int &value : numbers) cin >> value;
    int left = 0, right = n - 1;
    while (left <= right) {
        int middle = left + (right - left) / 2;
        if (numbers[middle] == target) {
            cout << middle << '\n';
            return 0;
        }
        if (numbers[middle] < target) left = middle + 1;
        else right = middle - 1;
    }
    cout << -1 << '\n';
    return 0;
}


