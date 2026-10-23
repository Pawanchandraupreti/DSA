// Split Array Largest Sum

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, parts;
    cin >> n >> parts;
    vector<int> a(n);
    long long left = 0, right = 0;
    for (int &x : a) {
        cin >> x;
        left = max(left, (long long)x);
        right += x;
    }
    while (left < right) {
        long long middle = (left + right) / 2, sum = 0;
        int groups = 1;
        for (int x : a) {
            if (sum + x > middle) {
                groups++;
                sum = 0;
            }
            sum += x;
        }
        if (groups <= parts) right = middle;
        else left = middle + 1;
    }
    cout << left << '\n';
    return 0;
}
