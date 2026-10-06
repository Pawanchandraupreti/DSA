// Find Pivot Index

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> numbers(n);
    int total = 0;
    for (int &value : numbers) {
        cin >> value;
        total += value;
    }
    int leftSum = 0;
    for (int i = 0; i < n; i++) {
        if (leftSum == total - leftSum - numbers[i]) {
            cout << i << '\n';
            return 0;
        }
        leftSum += numbers[i];
    }
    cout << -1 << '\n';
    return 0;
}


