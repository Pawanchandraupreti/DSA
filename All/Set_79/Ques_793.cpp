// Shortest Unsorted Continuous Subarray

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n), sorted;
    for (int &x : a) cin >> x;
    sorted = a;
    sort(sorted.begin(), sorted.end());
    int left = 0, right = n - 1;
    while (left < n && a[left] == sorted[left]) left++;
    while (right >= 0 && a[right] == sorted[right]) right--;
    cout << (left > right ? 0 : right - left + 1) << '\n';
    return 0;
}
