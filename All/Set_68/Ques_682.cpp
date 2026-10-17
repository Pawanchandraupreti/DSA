// Count Inversions

#include <bits/stdc++.h>
using namespace std;

long long mergeSort(vector<int> &a, int left, int right) {
    if (left >= right) return 0;
    int middle = (left + right) / 2;
    long long answer = mergeSort(a, left, middle) + mergeSort(a, middle + 1, right);
    vector<int> merged;
    int i = left, j = middle + 1;
    while (i <= middle && j <= right) {
        if (a[i] <= a[j]) merged.push_back(a[i++]);
        else {
            answer += middle - i + 1;
            merged.push_back(a[j++]);
        }
    }
    while (i <= middle) merged.push_back(a[i++]);
    while (j <= right) merged.push_back(a[j++]);
    copy(merged.begin(), merged.end(), a.begin() + left);
    return answer;
}

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &x : a) cin >> x;
    cout << (n == 0 ? 0 : mergeSort(a, 0, n - 1)) << '\n';
    return 0;
}
