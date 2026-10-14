// Kth Smallest Element in Sorted Matrix

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> values;
    for (int i = 0; i < n * n; i++) {
        int x;
        cin >> x;
        values.push_back(x);
    }
    nth_element(values.begin(), values.begin() + k - 1, values.end());
    cout << values[k - 1] << '\n';
    return 0;
}
