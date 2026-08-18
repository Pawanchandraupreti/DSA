// Count distinct elements in a sorted array

#include <bits/stdc++.h>
using namespace std;

int countDistinct(const vector<int>& arr) {
    int distinct = 0;
    for (int i = 0; i < (int)arr.size(); ++i) {
        if (i == 0 || arr[i] != arr[i - 1]) {
            ++distinct;
        }
    }
    return distinct;
}

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    cout << countDistinct(arr);
    return 0;
}
