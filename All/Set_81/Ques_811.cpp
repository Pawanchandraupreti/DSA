// K Closest Elements

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k, target;
    cin >> n >> k >> target;
    vector<int> a(n);
    for (int &x : a) cin >> x;
    int left = 0, right = n - k;
    while (left < right) {
        int middle = (left + right) / 2;
        if (target - a[middle] > a[middle + k] - target) left = middle + 1;
        else right = middle;
    }
    for (int i = left; i < left + k; i++) cout << a[i] << ' ';
    cout << '\n';
    return 0;
}
